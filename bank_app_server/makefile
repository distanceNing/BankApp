obj= admin_request.o client_request.o base_request.o \
	 tcp_socket.o main_loop.o mysql_data.o mysql_cpp.o main.o

VPATH=mysql_src

OBJSDIR=obj

#if [ ! -d $(OBJSDIR) ]; then \
#    mkdir -p $(OBJSDIR); \
#fi

demo:$(obj)
	g++    -o demo $(obj) -I/usr/include/mysql -L/usr/lib/mysql -lpthread -lmysqlclient 
main.o:main_loop.h main.cpp

mysql_data.o:mysql_data.h 

mysql_cpp.o:mysql_cpp.h mysql_data.h  uncopyable.h

main_loop.o:tcp_socket.h main_loop.h 

tcp_socket.o:tcp_socket.h

base_request.o:define.h tcp_socket.h base_request.h 

client_request.o:base_request.h client_request.h 

admin_request.o:base_request.h admin_request.h 

.PHONY:clean
clean:
	-rm $(obj) demo 

