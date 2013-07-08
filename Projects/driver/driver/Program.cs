using System;
using System.IO;
using System.IO.Pipes;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using System.Diagnostics;

namespace driver
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string[] _Arguements)
        {

            Process _Process = new Process();

            if (_Arguements.Length < 2)
            {

                Console.WriteLine("Error Incorrect usage, expected <executable> <file to be run> <second file to be run (in background)>");
                return;

            }

            _Process.StartInfo.UseShellExecute = true;
            //_Process.StartInfo.RedirectStandardOutput = true;
            _Process.StartInfo.FileName = _Arguements[0];
            //_Process.StartInfo.CreateNoWindow = false;
            //_Process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;

            using (AnonymousPipeServerStream _PipeServer = new AnonymousPipeServerStream(PipeDirection.Out, HandleInheritability.Inheritable))
            {

                // Pass the client process a handle to the server.
                _Process.StartInfo.Arguments = _PipeServer.GetClientHandleAsString();
                Console.WriteLine(_Process.StartInfo.FileName + " " + _Process.StartInfo.Arguments);

                Console.WriteLine(_PipeServer.GetClientHandleAsString());

                _Process.Start(); // start taking screen shots

                _Process = new Process();

                _Process.StartInfo.UseShellExecute = false;
                _Process.StartInfo.RedirectStandardOutput = true;
                _Process.StartInfo.FileName = _Arguements[1];
                _Process.StartInfo.CreateNoWindow = true;
                _Process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;

                _Process.Start(); // most likely is the selenium driver

                _Process.WaitForExit();

                try
                {
                    // Read user input and send that to the client process. 
                    using (StreamWriter _StreamWriter = new StreamWriter(_PipeServer))
                    {

                        _StreamWriter.AutoFlush = true;

                        // Send a 'sync message' and wait for client to receive it.
                        _StreamWriter.WriteLine("SYNC");

                    }
                }

                catch (IOException e)
                {
                    Console.WriteLine("[SERVER] Error: {0}", e.Message);
                }
            }

            Console.ReadLine();

        }
    }
}
