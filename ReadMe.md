# Air Mohanpur

This project aims to build a Flight booking in C.

## The Problem:

Design an interactive flight reservation system in C programming language. The customer should be able to choose a flight from a calendar through a unique customer id and see the availability of tickets. Each customer should be given three options for a ticket: infant, child and adult, with different prices. After the customer chooses the booking options, the system should generate the final ticket amount.

It should have two modes of access
- Admin
- User.

The allowed operations for each of these modes are:
- Admin: Make modifications in flight details
- User: Booking

There should be unique login ids for each. The system should ask for the login id and check it against a list. The admin and user ids for a person should be different. A person without a valid id should not be allowed to access the system. An Admin should be one related to the airport/airlines authorities. Users are the customers.

Each flight should have a unique id, availability, timing, source, destination etc.

In addition, a search facility should be present for both these modes allowing free-text search in general and also for specific fields of a flight.

## The Solution:

### Struct Scheme

- Admin:
  - Admin Id
  - Admin Password

- Flight:
  - Source
  - Destination
  - Time of departure
  - Time of arrival
  - Flight number
  - Total seats
  - Number of seat available
  - Flight availability

- Customer:?
  - Name
  - User Id
  - User password
  - Age
  - Gender
  - Phone Number
  - Mail id

- Passenger /(details):
  - Name
  - Category (infant, child, adult, senior citizen)
  - Age
  - Etc.

- Ticket:
  - Flight No. With airline name etc
  - Ticket id?
  - Destination
  - Source
  - Time -- Coming + going
  - Seat Details
  - Details about ticket holder

- FAQ:
  - Questions
  - Answer

- Billing System !!!!
  - Base fare
  - Insurance
  - Bla, Bla,........

- In flight features
  - Business Class Feature
  - Food

### Function Scheme

- Main
  - Admin
    - Authentication
    - Flight list

      Show list of Flights

      Add Flights

      Remove Flights

      Modify Flights

    - User List

      Show list of ...

      Add ..

      Remove ...

      Modify ...

    - Admin list

      Show list of ...

      Add ..

      Remove ...

      Modify ...

  - User
    - Authentication and SignUp
    - Booking History (Read from saved txt file)

      Show list all previous bookings

      Cancel Bookings
    - Search of Flight

      TBD
    - Filliing ticket Details

      Verify the prefilled Details + Fill rest of the details
    - Output of Final Ticket (PDF?  )
