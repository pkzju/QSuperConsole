# QSuperConsole
Super Console serial port serial bus modbus canbus tcp/ip

canopen协议参考：canopen/CANOpen_memento.pdf CANopen_meno.pdf
CanFestival源码手册：canopen/manual_en.pdf

0.  移植时win32时 错误出现在objdictdef.h文件 identity宏定义  改为IDENTITY后ok

1.  安装Beremiz-1.1_RC5.exe， 点击objdictedit.py 打开字典编辑器编辑对象字典
	例:(win32test.c中) 初始化对象字典：CO_Data win32test_Data = CANOPEN_NODE_DATA_INITIALIZER(win32test);
	CANOPEN_NODE_DATA_INITIALIZER宏定义在data.h中