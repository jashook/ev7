Imports System
Imports System.IO
Imports System.IO.Pipes

Module start_driver

    Sub Main(ByVal _Arguements() As String)

        Dim _Process As New Process()

        _Process.StartInfo.UseShellExecute = False
        _Process.StartInfo.RedirectStandardOutput = True
        _Process.StartInfo.FileName = "E:\\startup.bat"
        _Process.StartInfo.CreateNoWindow = True
        _Process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden

        _Process.Start()


    End Sub

End Module
