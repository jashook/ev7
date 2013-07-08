Imports System
Imports System.Threading
Imports System.IO
Imports System.IO.Pipes

Module controlform

    Private _g_continue = False
    Dim _g_lock_object As New Object
    Dim _g_pipe As String

    Sub Main(ByVal _Arguements() As String)

        If (_Arguements.Length > 0) Then

            Dim _Thread As New Thread(AddressOf Run)
            '_Thread.Start()

            Using _PipeClient As New AnonymousPipeClientStream(PipeDirection.In, "1004")

                Using _StreamWriter As New StreamReader(_PipeClient)

                    Dim _Temp As String

                    Do

                        _Temp = _StreamWriter.ReadLine()

                    Loop While _Temp.StartsWith("SYNC") = False

                End Using

            End Using

            _g_pipe = _Arguements(0)

            Console.WriteLine(_g_pipe)

            Dim _Args, _Program
            Dim _PictureCount As Integer

            _PictureCount = 0

            SyncLock _g_lock_object

                While _g_continue

                    _Program = "E:\screenshot-cmd"

                    _Args = " -o " + Environment.GetCommandLineArgs(1) + Convert.ToString(_PictureCount)

                    _PictureCount = _PictureCount + 1

                    Console.WriteLine(_Program + _Args)

                    Shell(_Program + _Args, AppWinStyle.Hide)

                    Thread.Sleep(Convert.ToInt32(Environment.GetCommandLineArgs(2)) * 1000)

                End While

            End SyncLock

        End If

    End Sub

    Sub Run()

        Console.WriteLine("HERE")

        Using _PipeClient As New AnonymousPipeClientStream(PipeDirection.In, "1004")

            Using _StreamWriter As New StreamReader(_PipeClient)

                Dim _Temp As String

                Do

                    _Temp = _StreamWriter.ReadLine()

                Loop While _Temp.StartsWith("SYNC") = False

            End Using

        End Using

        SyncLock _g_lock_object

            _g_continue = True

        End SyncLock

    End Sub

End Module

