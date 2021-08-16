Main函数前面添加
```cpp
//隐藏windows 终端显示界面
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
```