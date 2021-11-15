CREATE DATABASE CHMS;

CREATE TABLE Users (
    Id INT PRIMARY KEY IDENTITY(1,1),
    UserName VARCHAR(100) NOT NULL,
    Password VARCHAR(20) NOT NULL,
    Nic_No VARCHAR(12) NOT NULL,
    Address VARCHAR(250) NOT NULL,
    Tp INT NOT NULL,
    Email VARCHAR(100) NOT NULL,
    Salary FLOAT NOT NULL,
    User_Role BIT NOT NULL,
);



CREATE TABLE Buildings (
    Id INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(20) NOT NULL
);

INSERT INTO Buildings(Name) VALUES ('Building|B|001'), ('Building|B|002'), ('Building|G|003');



CREATE TABLE Rooms (
    Id INT PRIMARY KEY IDENTITY(1,1),
    Building_Id INT NOT NULL,
    Room_Type CHAR NOT NULL,
    Rental FLOAT NOT NULL
)

ALTER TABLE Rooms
ADD CONSTRAINT FK_Building_Id
FOREIGN KEY (Building_Id) REFERENCES Buildings(Id);

INSERT INTO Rooms(Building_Id, Room_Type, Rental) VALUES
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'S', 10000.00),
(1, 'D', 18000.00),
(1, 'D', 18000.00),
(1, 'D', 18000.00),
(1, 'D', 18000.00),
(1, 'D', 18000.00),
(1, 'D', 18000.00),
(1, 'D', 18000.00),
(1, 'D', 18000.00),
(1, 'D', 18000.00),
(1, 'D', 18000.00),
(1, 'D', 18000.00),
(1, 'D', 18000.00),
(2, 'S', 15000.00),
(2, 'S', 15000.00),
(2, 'S', 15000.00),
(2, 'S', 15000.00),
(2, 'S', 15000.00),
(2, 'S', 15000.00),
(2, 'S', 15000.00),
(2, 'S', 15000.00),
(2, 'S', 15000.00),
(2, 'S', 15000.00),
(2, 'S', 15000.00),
(2, 'D', 25000.00),
(2, 'D', 25000.00),
(2, 'D', 25000.00),
(2, 'D', 25000.00),
(2, 'D', 25000.00),
(3, 'S', 10000.00),
(3, 'S', 10000.00),
(3, 'S', 10000.00),
(3, 'S', 10000.00),
(3, 'S', 10000.00),
(3, 'S', 10000.00),
(3, 'S', 10000.00),
(3, 'S', 10000.00),
(3, 'D', 18000.00),
(3, 'D', 18000.00),
(3, 'D', 18000.00),
(3, 'D', 18000.00),
(3, 'D', 18000.00),
(3, 'D', 18000.00),
(3, 'D', 18000.00);



    SELECT COUNT(DISTINCT Id) AS Room_Count FROM Rooms 
    SELECT COUNT(DISTINCT Room_Id) AS Reserved_Room_Count FROM Students;

    SELECT * FROM Students


SELECT COUNT(Id) AS Student_Count, Gender  FROM Students GROUP BY Gender;


SELECT COUNT(Id) AS Student_Count, University, AVG(COUNT(Id)) AS Average FROM Students GROUP BY University

SELECT COUNT(Id) AS Staff_Count FROM Users WHERE User_Role = 0;


SELECT * FROM Buildings;

SELECT * FROM Rooms;
SELECT
(SELECT b.Name FROM Buildings b WHERE b.Id = r.Building_Id) AS Building,
COUNT(r.Id)
AS ROOMS FROM Rooms r GROUP BY Building_Id;


SELECT b.Name,
(SELECT COUNT(r.ID) FROM Rooms r WHERE r.Building_Id = b.Id AND r.Room_Type = 'S') AS 'Single Total',
(SELECT COUNT(x.ID) FROM Rooms x WHERE x.Building_Id = b.Id AND x.Room_Type = 'D') AS 'Double Total',
(SELECT y.Free FROM(
    SELECT COUNT(x.Room_Id) AS 'Free',x.Room_Type, x.Building_Id FROM (
        SELECT DISTINCT s.Room_Id, r.Room_Type, r.Building_Id FROM Students s JOIN Rooms r ON s.Room_Id = r.Id)x
        GROUP BY x.Building_Id, x.Room_Type
    )y  WHERE y.Building_Id = b.Id AND y.Room_Type = 'S') AS 'Rented Single',
(SELECT y.Free FROM(
    SELECT COUNT(x.Room_Id) AS 'Free',x.Room_Type, x.Building_Id FROM (
        SELECT DISTINCT s.Room_Id, r.Room_Type, r.Building_Id FROM Students s JOIN Rooms r ON s.Room_Id = r.Id)x
        GROUP BY x.Building_Id, x.Room_Type
    )y  WHERE y.Building_Id = b.Id AND y.Room_Type = 'D') AS 'Rented Double'
 FROM Buildings b;


SELECT COUNT(x.Room_Id) AS 'Free',x.Room_Type, x.Building_Id FROM (
SELECT DISTINCT s.Room_Id, r.Room_Type, r.Building_Id FROM Students s JOIN Rooms r ON s.Room_Id = r.Id)x
GROUP BY x.Building_Id, x.Room_Type;


SELECT DISTINCT s.Room_Id, r.Room_Type, r.Building_Id FROM Students s JOIN Rooms r ON s.Room_Id = r.Id;

 
SELECT UserName, TP, Email, Salary FROM Users WHERE ID <> 1;

