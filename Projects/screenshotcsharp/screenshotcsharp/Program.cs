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

         string _Program = "E:\\screenshot-cmd.exe";

         bool _Continue = true;

         while (_Continue)
         {

            string _Args = " -o " + _Arguements[0] + Convert.ToString(_PictureCount++) + ".png";

            Process _Process = new Process();

            _Process.StartInfo.FileName = _Program;
            _Process.StartInfo.UseShellExecute = false;
            _Process.StartInfo.CreateNoWindow = true;
            _Process.StartInfo.RedirectStandardOutput = true;
            _Process.StartInfo.Arguments = _Args;

            _Process.Start();

            Thread.Sleep(Convert.ToInt32(_Arguements[1]));

            lock (_g_lock_object)
            {
               
               _Continue = _g_continue;

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

            } while (!_Temp.StartsWith("SYNC"));

         }

         lock (_g_lock_object)
         {

            _g_continue = false;

         }

         pipeClient.Close();

      }

   }
}
