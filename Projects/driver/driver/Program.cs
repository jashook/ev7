using System;
using System.IO;
using System.IO.Pipes;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using System.Diagnostics;
using System.Threading;

namespace driver
{
   static class Program
   {

      private static string _String;

      /// <summary>
      /// The main entry point for the application.
      /// </summary>
      //[STAThread]
      static void Main(string[] _Arguements)
      {

         Process _Process = new Process();

         if (_Arguements.Length < 2)
         {

            Console.WriteLine("Error Incorrect usage, expected <executable> <file to be run> <second file to be run (in background)>");
            return;

         }

         _Process.StartInfo.UseShellExecute = false;
         _Process.StartInfo.RedirectStandardOutput = true;
         _Process.StartInfo.FileName = _Arguements[0];
         _Process.StartInfo.CreateNoWindow = false;
         _Process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
         _Process.StartInfo.Arguments = _Arguements[2];

         NamedPipeServerStream _PipeServer = new NamedPipeServerStream("screenshotpipe", PipeDirection.InOut, 1);

         // Pass the client process a handle to the server.
         Console.WriteLine(_Process.StartInfo.FileName + " " + _Process.StartInfo.Arguments);

         _String = _Process.StartInfo.Arguments;
         //_String = _PipeServer.GetClientHandleAsString();

         _Process.Start(); // start taking screen shots

         
         _Process = new Process();

         _Process.StartInfo.UseShellExecute = false;
         _Process.StartInfo.RedirectStandardOutput = true;
         _Process.StartInfo.FileName = _Arguements[1];
         _Process.StartInfo.CreateNoWindow = true;
         _Process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;

         _Process.Start(); // most likely is the selenium driver

         _Process.WaitForExit();

         // Wait for a client to connect
         _PipeServer.WaitForConnection();

         try
         {
            // Read the request from the client. Once the client has 
            // written to the pipe its security token will be available.

            try
            {
               // Read user input and send that to the client process. 
               using (StreamWriter _StreamWriter = new StreamWriter(_PipeServer))
               {

                  _StreamWriter.AutoFlush = true;

                  // Send a 'sync message' and wait for client to receive it.
                  _StreamWriter.WriteLine("SYNC");
                  _PipeServer.WaitForPipeDrain();

               }
            }

            catch (IOException e)
            {
               Console.WriteLine("[SERVER] Error: {0}", e.Message);
            }

         }
         // Catch the IOException that is raised if the pipe is broken 
         // or disconnected. 
         catch (IOException e)
         {
            Console.WriteLine("ERROR: {0}", e.Message);
         }
         
         _PipeServer.Close();

      }

      private static void test_client(object _Data)
      {

         Console.WriteLine(_String);

         using (PipeStream pipeClient = new AnonymousPipeClientStream(PipeDirection.In, _String))
         {

            using (StreamReader sr = new StreamReader(pipeClient))
            {
               // Display the read text to the console 
               string temp;

               // Wait for 'sync message' from the server. 
               do
               {
                  Console.WriteLine("[CLIENT] Wait for sync...");
                  temp = sr.ReadLine();
               }
               while (!temp.StartsWith("SYNC"));

               Console.WriteLine("SYNCED, exiting");

            }

         }

      }

   }

}
