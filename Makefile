
CC=gcc

all: my_app

file.o: file.c
	$(CC) -c $^

admin.o: admin.c
	$(CC) -c $^

user.o: user.c
	$(CC) -c $^

print_ticket.o: print_ticket.c
	$(CC) -c $^

booking_history.o: booking_history.c
	$(CC) -c $^

flights.o: flights.c
	$(CC) -c $^

my_app: welcome.c file.o user.o admin.o flights.o booking_history.o print_ticket.o
	$(CC) -o $@ $^

clean:
	rm my_app *.o