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
      /// <summary>
      /// The main entry point for the application.
      /// </summary>
      //[STAThread]
      static void Main(string[] args)
      {

         Console.ReadLine();

         if (args.Length > -1)
         {
            NamedPipeClientStream pipeClient =
                    new NamedPipeClientStream(".", "screenshotpipe", PipeDirection.InOut, PipeOptions.None, TokenImpersonationLevel.Impersonation);

                Console.WriteLine("Connecting to server...\n");
                pipeClient.Connect();

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

                }

                pipeClient.Close();
            }

         Console.Write("[CLIENT] Press Enter to continue...");
         Console.ReadLine();
      }
   }
}
