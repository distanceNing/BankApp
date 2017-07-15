obj= AdmainRequest.o ClientRequest.o BaseRequest.o Csocket.o MainLoop.cpp mysql_data.o mysql_cpp.o main.o
demo:$(obj)
	g++ $(obj) -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient -o demo
main.o:MainLoop.h main.cpp
	g++ -c -I/usr/include/mysql main.cpp 
mysql_data.o:mysql_data.h mysql_data.cpp
	g++ -c mysql_data.cpp
mysql_cpp.o:mysql_cpp.h mysql_data.h mysql_cpp.cpp uncopyable.h
	g++ -c -I/usr/include/mysql mysql_cpp.cpp -L/usr/lib/mysql -lmysqlclient 
MainLoop.o:Csocket.h MainLoop.h MainLoop.cpp
	g++ -c -I/usr/include/mysql MainLoop.cpp
Csocket.o:Csocket.h Csocket.cpp
	g++ -c Csocket.cpp
BaseRequest.o:define.h Csocket.h BaseRequest.h BaseRequest.cpp
	g++ -c -I/usr/include/mysql BaseRequest.cpp
ClientRequest.o:BaseRequest.h ClientRequest.h ClientRequest.cpp
	g++ -c -I/usr/include/mysql ClientRequest.cpp
AdmainRequest.o:BaseRequest.h AdmainRequest.h AdmainRequest.cpp
	g++ -c -I/usr/include/mysql AdmainRequest.cpp
.PHONY:clean
clean:
	-rm *.o

