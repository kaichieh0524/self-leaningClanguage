# 2020/04/18 C/C++ 環境建置
---
## Download Visual Studio Code or Visual Studio (IDE)
https://visualstudio.microsoft.com/zh-hant/?rr=https%3A%2F%2Fwww.google.com%2F


![1](https://github.com/kaichieh0524/self-leaningClanguage/blob/master/20200418%20vs%20code%20environment%20setup/figure/1.png)

---
## Download MMinGW-w64
https://sourceforge.net/projects/mingw-w64/\

Change Architecture to x86_64

![1](https://github.com/kaichieh0524/self-leaningClanguage/blob/master/20200418%20vs%20code%20environment%20setup/figure/2.PNG) 
---
   
## Download Pre-Built-Binaries LLVM (Only Windows-64bits) 
https://releases.llvm.org/download.html\
![1](https://github.com/kaichieh0524/self-leaningClanguage/blob/master/20200418%20vs%20code%20environment%20setup/figure/3.PNG)

![1](https://github.com/kaichieh0524/self-leaningClanguage/blob/master/20200418%20vs%20code%20environment%20setup/figure/4.PNG)

## Copy the all files in mingw-w64 to LLVM

![1](https://github.com/kaichieh0524/self-leaningClanguage/blob/master/20200418%20vs%20code%20environment%20setup/figure/5.PNG)


## Install VSCode extension 
1.C/C++\
2.C/C++ Clang Command Adapter\
3.Code Runner

## Creat a project and creat a folder (.vscode)
creat c_cpp_properties.json”、”launch.json”、”settings.json” and “tasks.json” in .vscode

### c_cpp_properties.json
    {
      "configurations": [
        {
           "name": "MinGW",
           "intelliSenseMode": "clang-x64",
           "compilerPath": "C:/LLVM/bin/gcc.exe",
           "includePath": [
              "${workspaceFolder}"
           ],
           "defines": [],
           "browse": {
              "path": [
                "${workspaceFolder}"
               ],
            "limitSymbolsToIncludedHeaders": true,
            "databaseFilename": ""
            },
        "cStandard": "c11",
        "cppStandard": "c++17"
        }
     ],
     "version": 4
    }

 ### lauch.json
     {
       "version": "0.2.0",
       "configurations": [
         {
            "name": "(gdb) Launch", 
            "type": "cppdbg", 
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}.exe", 
            "args": [], 
            "stopAtEntry": true,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true, 
            "internalConsoleOptions": "neverOpen",
            "MIMode": "gdb",
            "miDebuggerPath": "gdb.exe", 
            "setupCommands": [ 
               {
                  "description": "Enable pretty-printing for gdb",
                  "text": "-enable-pretty-printing",
                  "ignoreFailures": false
               }
             ],
             "preLaunchTask": "Compile" 
            }
         ]
     }

### settings.json
    {
        "files.defaultLanguage": "cpp", 
        "editor.formatOnType": true, 
        "editor.snippetSuggestions": "top",
        "code-runner.runInTerminal": true,
        "code-runner.executorMap": {
            "c": "cd $dir && clang $fileName -o $fileNameWithoutExt.exe -Wall -g -Og -static-libgcc -fcolor-diagnostics --target=x86_64-w64-mingw -std=c11 && $dir$fileNameWithoutExt",
            "cpp": "cd $dir && clang++ $fileName -o $fileNameWithoutExt.exe -Wall -g -Og -static-libgcc -fcolor-diagnostics --target=x86_64-w64-mingw -std=c++17 && $dir$fileNameWithoutExt"
        }, 
        "code-runner.saveFileBeforeRun": true, 
        "code-runner.preserveFocus": true, 
        "code-runner.clearPreviousOutput": false, 
        "C_Cpp.clang_format_sortIncludes": true,
        "C_Cpp.intelliSenseEngine": "Default", 
        "C_Cpp.errorSquiggles": "Disabled", 
        "C_Cpp.autocomplete": "Disabled",
        "clang.cflags": [
            "--target=x86_64-w64-mingw",
            "-std=c11",
            "-Wall"
        ],
        "clang.cxxflags": [ 
          "--target=x86_64-w64-mingw",
          "-std=c++17",
          "-Wall"
        ],
        "clang.completion.enable": true 
    }
### tasks.json
    {
        "version": "2.0.0",
        "tasks": [
             {
                 "label": "Compile", 
                 "command": "clang++", 
                 "args": [
                    "${file}",
                    "-o",
                    "${fileDirname}/${fileBasenameNoExtension}.exe",
                    "-g", 
                    "-Wall",
                    "-static-libgcc",
                    "-fcolor-diagnostics",
                    "--target=x86_64-w64-mingw", 
                    "-std=c++17" 
                ], 
                "type": "shell", 
                "group": {
                    "kind": "build",
                    "isDefault": true 
                },
                "presentation": {
                    "echo": true,
                    "reveal": "always", 
                    "focus": false, 
                    "panel": "shared" 
                 }
                // "problemMatcher":"$gcc" 
            }
        ]
    }