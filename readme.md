#### BankApp:
    一个简单的银行管理系统。
#### ban_kApp：
    MFC写的客户端程序。
#### qt_ui_bank_app
    用QT代替MFC程序，简单好用，界面友好。
#### bank_app_server：
    服务器程序。

    简单架构：为已建立连接的客户端分配一个线程去处理请求。
    下一步：
        利用I\O复用技术，减少线程数量，增加服务器的并发处理量。
