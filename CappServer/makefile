obj= admin_request.o client_request.o base_request.o Csocket.o main_loop.o mysql_data.o mysql_cpp.o main.o
demo:$(obj)
	g++ $(obj) -I/usr/include/mysql -L/usr/lib/mysql -lpthread -lmysqlclient -o demo
main.o:main_loop.h main.cpp
	g++ -c -I/usr/include/mysql main.cpp 
mysql_data.o:mysql_data.h mysql_data.cpp
	g++ -c mysql_data.cpp
mysql_cpp.o:mysql_cpp.h mysql_data.h  uncopyable.h
	g++ -c -I/usr/include/mysql mysql_cpp.cpp -L/usr/lib/mysql -lmysqlclient 
main_loop.o:Csocket.h main_loop.h 
	g++ -c -I/usr/include/mysql main_loop.cpp 
Csocket.o:Csocket.h Csocket.cpp
	g++ -c Csocket.cpp
base_request.o:define.h Csocket.h base_request.h base_request.cpp
	g++ -c -I/usr/include/mysql base_request.cpp
client_request.o:base_request.h client_request.h client_request.cpp
	g++ -c -I/usr/include/mysql client_request.cpp
admin_request.o:base_request.h admin_request.h admin_request.cpp
	g++ -c -I/usr/include/mysql admin_request.cpp

.PHONY:clean
clean:
	-rm *.o

