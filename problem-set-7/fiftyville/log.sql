-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find crime scene reports from Humphrey Street on 28/7
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

-- Read interview transcripts from 28/7
SELECT name, transcript FROM interviews WHERE month = 7 AND day = 28;
-- Ruth: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- Eugene: I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- Raymond: As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- View activity and license plates from bakery security logs from 28/7 between 10:15 and 10:25
SELECT minute, activity, license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;
-- 5P2BI95 | 94KL13X | 6P58WS2 | 4328GD8 | G412CB7 | L93JTIZ | 322W7JE | 0NTHK55

-- View account numbers and amounts withdrawn from the Leggett Street ATM on 28/7
SELECT account_number, amount FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
-- 28500762, 48 | 28296815, 20 | 76054385, 60 | 49610011, 50 | 16153065, 80 | 25506511, 20 | 81061156, 30 | 26013199, 35

-- View callers, receivers, and call durations from phone calls under a minute on 28/7
SELECT caller, receiver, duration FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60;

-- View airport information
SELECT * FROM airports;
-- Fiftyville ID: 8

-- View flight IDs and destinations of earliest flights from Fiftyville on 29/7/21
SELECT id, destination_airport_id, hour, minute FROM flights WHERE origin_airport_id = 8 AND year = 2021 AND month = 7 AND day = 29;
-- Suspect took a flight (36) to LaGuardia Airport (LGA, 4) in New York City on 8:20

-- View names and passport numbers of people with suspected phone numbers and license plates
SELECT id, name, passport_number FROM people WHERE phone_number IN ('(130) 555-0289', '(499) 555-9472', '(367) 555-5533', '(499) 555-9472', '(286) 555-6063', '(770) 555-1861', '(031) 555-6622', '(826) 555-1652', '(338) 555-6650') AND license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55');
-- 398010, Sofia, 1695452385 | 514354, Diana, 3592750733 | 560886, Kelsey, 8294398571 | 686048, Bruce, 5773159633

-- View bank accounts matching people's IDs
SELECT account_number, person_id, creation_year FROM bank_accounts WHERE person_id IN ('398010', '514354', '560886', '686048');
-- Bruce, 49610011, 2010 | Diana, 26013199, 2012

-- View flight seats of suspects
SELECT seat, passport_number FROM passengers WHERE flight_id = 36 AND passport_number IN ('3592750733', '5773159633');
-- Seat 4A, 5773159633 | Bruce is the criminal

-- Find accomplice by finding receiver of phone call from (367) 555-5533
SELECT receiver FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60 AND caller = '(367) 555-5533';
-- Accomplice's phone number is (375) 555-8161

-- Find accomplice's name
SELECT name FROM people WHERE phone_number = '(375) 555-8161';
-- Accomplice is Robin
