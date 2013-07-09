using System;
using System.IO;
using System.IO.Pipes;
using System.Text;
using System.Security.Principal;
using System.Diagnostics;
using System.Threading;

namespace screenshotcsharp
{
   static class Program
   {

      static private bool _g_continue = true;
      static private Object _g_lock_object = new Object();

      /// <summary>
      /// The main entry point for the application.
      /// </summary>
      //[STAThread]
      static void Main(string[] _Arguements)
      {
         
         Thread _Thread = new Thread(run);
         _Thread.Start();

         int _PictureCount = 0;

         
         string _Program = "E:\\screenshot-cmd";

         lock (_g_lock_object)
         {

            while (_g_continue)
            {

               string _Args = " -o " + _Arguements[1] + Convert.ToString(_PictureCount++);

               Process _Process = new Process();

               _Process.StartInfo.FileName = _Program;
               _Process.StartInfo.UseShellExecute = true;
               _Process.StartInfo.CreateNoWindow = true;
               _Process.StartInfo.RedirectStandardOutput = true;
               _Process.StartInfo.Arguments = _Args;

               _Process.Start();

               Thread.Sleep(Convert.ToInt32(_Arguements[2]));
   
            }

         }

      }

      static void run(Object _Data)
      {

         NamedPipeClientStream pipeClient = new NamedPipeClientStream(".", "screenshotpipe", PipeDirection.InOut, PipeOptions.None, TokenImpersonationLevel.Impersonation);

         Console.WriteLine("Connecting to server...\n");
         pipeClient.Connect();

         using (StreamReader sr = new StreamReader(pipeClient))
         {
            
            string _Temp;

            do
            {

              _Temp = sr.ReadLine();

            }
            while (!_Temp.StartsWith("SYNC"));

         }

         lock (_g_lock_object)
         {

            _g_continue = false;

         }

         pipeClient.Close();

      }

   }
}
