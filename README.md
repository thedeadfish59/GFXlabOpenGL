### GFXlabOpenGL
All codes of Graphics Lab will be found here

### Building and compiling instructions:
1> Install CodeBlocks, then do following:

>>Paste glut.h to C:\Program Files (x86)\CodeBlocks\MinGW\include\GL\*here* 

>>Paste glut32.dll to C:\Windows\System32\*here* and C:\Windows\SysWOW64\*here* [Note: If you dont have SysWOW64, just skip and paste only at system32]

>>Paste glut.lib to C:\Program Files (x86)\CodeBlocks\MinGW\lib\*here* 

Okay, now open up codeblocks, and Go to settings>Compiler, here, you will find Linker Settings, click on add, just type this on

`C:\Program Files (x86)\CodeBlocks\MinGW\lib\glut32.lib`
and hit okay, for better understanding, do just like below screenshot leads you to do! 

![](https://github.com/thedeadfish59/GFXlabOpenGL/raw/master/Screenshots/1.png)

![](https://github.com/thedeadfish59/GFXlabOpenGL/raw/master/Screenshots/2.png)

Then, click on File>New>Project

![](https://github.com/thedeadfish59/GFXlabOpenGL/raw/master/Screenshots/3.png)

Select GLUTproject

![](https://github.com/thedeadfish59/GFXlabOpenGL/raw/master/Screenshots/4.png)

Then specify project/program title there

![](https://github.com/thedeadfish59/GFXlabOpenGL/raw/master/Screenshots/5.png)

Then select next, mention the glut directory, it will be

`C:\Program Files (x86)\CodeBlocks\MinGW`

![](https://github.com/thedeadfish59/GFXlabOpenGL/raw/master/Screenshots/6.png)

Then hit Finish

![](https://github.com/thedeadfish59/GFXlabOpenGL/raw/master/Screenshots/7.png)

Then on Left pane, under Sources, there will be main.cpp, double click on that, then type your code, save, build, execute! Its easy eh?

![](https://github.com/thedeadfish59/GFXlabOpenGL/raw/master/Screenshots/8.png)


2>For Microsoft Visual C++ 6.0 
Graphic codes which uses OpenGL library and runtime, needs some dependencies while compiling on any machine.
Our lecturer Shipu Madam recommends Microsoft Visual C++ , to make this program able to compile these codes, we will need:

>>glut.h (To be pasted at YOUR_INSTALLED_DIRECTORY\Visual Studio\VC98\INCLUDE\GL\*here*)

>>glut32.dll (The latest one which got Windows 10 support, to be pasted at C:\Windows\System32\*here*)

>>glut.lib (To be pasted at YOUR_INSTALLED_DIRECTORY\Visual Studio\VC98\Lib\*here* )


further more questions can be asked on our group

#You are free to fork and use codes :) 
