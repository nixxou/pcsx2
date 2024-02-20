#include "MameHookerProxy.h"

MameHookerProxy& MameHookerProxy::GetInstance()
{
  // TODO: insérer une instruction return ici
  static MameHookerProxy s_instance;
  return s_instance;
}

bool MameHookerProxy::fileExists(const wchar_t* filePath)
{
  DWORD fileAttributes = GetFileAttributesW(filePath);
  return (fileAttributes != INVALID_FILE_ATTRIBUTES &&
          !(fileAttributes & FILE_ATTRIBUTE_DIRECTORY));
}

void MameHookerProxy::launchProgram(const char* programPath, PROCESS_INFORMATION& processInfo)
{
  STARTUPINFOA startupInfo;
  ZeroMemory(&startupInfo, sizeof(startupInfo));
  startupInfo.cb = sizeof(startupInfo);

  if (!CreateProcessA(NULL,                // No module name (use command line)
                      (LPSTR)programPath,  // Command line
                      NULL,                // Process handle not inheritable
                      NULL,                // Thread handle not inheritable
                      FALSE,               // Set handle inheritance to FALSE
                      0,                   // No creation flags
                      NULL,                // Use parent's environment block
                      NULL,                // Use parent's starting directory
                      &startupInfo,        // Pointer to STARTUPINFO structure
                      &processInfo         // Pointer to PROCESS_INFORMATION structure
                      ))
  {
    //std::cerr << "Error launching program: " << GetLastError() << std::endl;
  }
}

std::string MameHookerProxy::getExecutableDirectory()
{
  char buffer[MAX_PATH];
  GetModuleFileNameA(NULL, buffer, MAX_PATH);
  std::string fullPath(buffer);
  size_t found = fullPath.find_last_of("\\/");
  return fullPath.substr(0, found);
}

void MameHookerProxy::Init()
{
  pipeConnected = false;
  processInfo = nullptr;  // Initialiser à nullptr
}

void MameHookerProxy::CloseGame()
{
  activeGame = "";
  active = false;
  bool needForceClose = true;
  if (processInfo != nullptr)
  {
    if (pipeConnected)
    {
      std::string message = "CLOSE";
      DWORD bytesWritten;
      DWORD messageLength = static_cast<DWORD>(message.length());
      if (!WriteFile(hPipe, message.c_str(), messageLength, &bytesWritten, NULL))
      {
        CloseHandle(hPipe);
        pipeConnected = false;
      }
      else
      {
        needForceClose = false;
      }
    }

    if (needForceClose)
    {
      DWORD exitCode;
      if (GetExitCodeProcess((*processInfo).hProcess, &exitCode) && exitCode == STILL_ACTIVE)
      {
        // Le programme est toujours en cours d'exécution, tuez-le
        if (!TerminateProcess((*processInfo).hProcess, 0))
        {

        }
        CloseHandle((*processInfo).hProcess);
        CloseHandle((*processInfo).hThread);
      }
    }
  }

  
  if (hPipeGunA != nullptr)
  {
    CloseHandle(hPipeGunA);
  }

  if (hPipeGunB != nullptr)
  {
    CloseHandle(hPipeGunB);
  }

  if (hPipeGunC != nullptr)
  {
    CloseHandle(hPipeGunC);
  }

  if (hPipeGunD != nullptr)
  {
    CloseHandle(hPipeGunD);
  }
  
  if (hPipe != nullptr)
  {
    CloseHandle(hPipe);
  }

  pipeConnected = false;
  pipeConnectedGunA = false;
  pipeConnectedGunB = false;
  pipeConnectedGunC = false;
  pipeConnectedGunD = false;

}

void MameHookerProxy::Gunshot(int gunIndex)
{
  if (!pipeConnected || !active)
    return;

  
  std::string message = "1";
  if (gunIndex == 0)
  {
    if (!pipeConnectedGunA)
    {
      if (hPipeGunA != nullptr)
      {
        CloseHandle(hPipeGunA);
      }
      hPipeGunA =
          CreateFileA("\\\\.\\pipe\\MameHookerProxyRecoilGunA", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
      if (hPipeGunA != INVALID_HANDLE_VALUE)
      {
        pipeConnectedGunA = true;
      }
    }
    if (pipeConnectedGunA)
    {
      DWORD bytesWritten;
      DWORD messageLength = static_cast<DWORD>(message.length());
      if (!WriteFile(hPipeGunA, message.c_str(), messageLength, &bytesWritten, NULL))
      {
        CloseHandle(hPipeGunA);
        pipeConnectedGunA = false;
      }
    }
  }
  if (gunIndex == 1)
  {
    if (!pipeConnectedGunB)
    {
      if (hPipeGunB != nullptr)
      {
        CloseHandle(hPipeGunB);
      }
      hPipeGunB = CreateFileA("\\\\.\\pipe\\MameHookerProxyRecoilGunB", GENERIC_WRITE, 0, NULL,
                              OPEN_EXISTING, 0, NULL);
      if (hPipeGunB != INVALID_HANDLE_VALUE)
      {
        pipeConnectedGunB = true;
      }
    }
    if (pipeConnectedGunB)
    {
      DWORD bytesWritten;
      DWORD messageLength = static_cast<DWORD>(message.length());
      if (!WriteFile(hPipeGunB, message.c_str(), messageLength, &bytesWritten, NULL))
      {
        CloseHandle(hPipeGunB);
        pipeConnectedGunB = false;
      }
    }
  }
  if (gunIndex == 2)
  {
    if (!pipeConnectedGunC)
    {
      if (hPipeGunC != nullptr)
      {
        CloseHandle(hPipeGunC);
      }
      hPipeGunC = CreateFileA("\\\\.\\pipe\\MameHookerProxyRecoilGunC", GENERIC_WRITE, 0, NULL,
                              OPEN_EXISTING, 0, NULL);
      if (hPipeGunC != INVALID_HANDLE_VALUE)
      {
        pipeConnectedGunC = true;
      }
    }
    if (pipeConnectedGunC)
    {
      DWORD bytesWritten;
      DWORD messageLength = static_cast<DWORD>(message.length());
      if (!WriteFile(hPipeGunC, message.c_str(), messageLength, &bytesWritten, NULL))
      {
        CloseHandle(hPipeGunC);
        pipeConnectedGunC = false;
      }
    }
  }
  if (gunIndex == 3)
  {
    if (!pipeConnectedGunD)
    {
      if (hPipeGunD != nullptr)
      {
        CloseHandle(hPipeGunD);
      }
      hPipeGunD = CreateFileA("\\\\.\\pipe\\MameHookerProxyRecoilGunD", GENERIC_WRITE, 0, NULL,
                              OPEN_EXISTING, 0, NULL);
      if (hPipeGunD != INVALID_HANDLE_VALUE)
      {
        pipeConnectedGunD = true;
      }
    }
    if (pipeConnectedGunD)
    {
      DWORD bytesWritten;
      DWORD messageLength = static_cast<DWORD>(message.length());
      if (!WriteFile(hPipeGunD, message.c_str(), messageLength, &bytesWritten, NULL))
      {
        CloseHandle(hPipeGunD);
        pipeConnectedGunD = false;
      }
    }
  }
}

void MameHookerProxy::SendState(std::string key, int value)
{
  if (!pipeConnected || !active)
    return;

  std::string message = key + ":" + std::to_string(value);
  DWORD bytesWritten;
  DWORD messageLength = static_cast<DWORD>(message.length());
  if (!WriteFile(hPipe, message.c_str(), messageLength, &bytesWritten, NULL))
  {
    CloseHandle(hPipe);
    hPipe = CreateFileA("\\\\.\\pipe\\MameHookerProxyControl", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hPipe != INVALID_HANDLE_VALUE)
    {
      pipeConnected = true;
    }
    else
    {
      pipeConnected = false;
    }
  }

}

void MameHookerProxy::StartGame(std::string id)
{
  if (id == activeGame)
    return;
  if (id == "")
    return;

  activeGame = id;

  active = true;

  if (hPipe != nullptr)
  {
    CloseHandle(hPipe);
  }
  if (hPipeGunA != nullptr)
  {
    CloseHandle(hPipeGunA);
  }

  if (hPipeGunB != nullptr)
  {
    CloseHandle(hPipeGunB);
  }

  if (hPipeGunC != nullptr)
  {
    CloseHandle(hPipeGunC);
  }

  if (hPipeGunD != nullptr)
  {
    CloseHandle(hPipeGunD);
  }
  pipeConnected = false;
  pipeConnectedGunA = false;
  pipeConnectedGunB = false;
  pipeConnectedGunC = false;
  pipeConnectedGunD = false;

  std::string executableDirectory = getExecutableDirectory();
  std::string programPath = executableDirectory + "\\MameOutputSender.exe";
  std::string arguments =
      "gamename=\"" + id +
      "\" "
      "outputs=\"GunRecoil_P1,GunRecoil_P2,TriggerPress_P1,TriggerPress_P2\"";

  std::string commandLine = std::string(programPath) + " " + std::string(arguments);


  std::wstring wideProgramPath(programPath.begin(), programPath.end());
  if (fileExists(wideProgramPath.c_str()))
  {
    processInfo = new PROCESS_INFORMATION();

    STARTUPINFOA startupInfo;
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    if (!CreateProcessA(NULL,                             // No module name (use command line)
                        (LPSTR)commandLine.c_str(),  // Command line
                       NULL,                             // Process handle not inheritable
                       NULL,                             // Thread handle not inheritable
                       FALSE,                            // Set handle inheritance to FALSE
                       0,                                // No creation flags
                       NULL,                             // Use parent's environment block
                       NULL,                             // Use parent's starting directory
                       &startupInfo,                     // Pointer to STARTUPINFO structure
                       processInfo))
    {
      delete processInfo;     // Libérer la mémoire en cas d'échec
      processInfo = nullptr;  // Réinitialiser à nullptr
    }
  }
  if (processInfo != nullptr)
  {

     std::thread([=]() {
      int compteur = 0;
      //std::this_thread::sleep_for(std::chrono::seconds(1));  // Attendre 5 secondes
      if (!active)
        return;
      while (active && compteur < 50)
      {
        compteur++;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        hPipe = CreateFileA("\\\\.\\pipe\\MameHookerProxyControl", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0,NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
          pipeConnected = false;
          
        }
        else
        {
          pipeConnected = true;
          break;
        }
      }
    }).detach();  // Détacher le thread pour éviter de bloquer la sortie du programme
  }
}





