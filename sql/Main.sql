CREATE DATABASE CHMS;

CREATE TABLE Students (
    Id INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(100) NOT NULL,
    Nic_No VARCHAR(12) NOT NULL,
    Address VARCHAR(250) NOT NULL,
    Tp INT NOT NULL,
    Email VARCHAR(100) NOT NULL,
    University VARCHAR(80),
    Room_Id INT NOT NULL,
);

INSERT INTO Students(Name, Nic_No, Address, TP, Email, University, Room_Id) VALUES
('Mahinda Rajapaksha', '583181098v', '1, Madamulana Rd, Hambanthota', 0771729181, 'mahinda@slpp.com', 'NSBM', 1),
('Gotabaya Rajapaksha', '653181018v', '2, Madamulana Rd, Hambanthota', 0771723481, 'gota@slpp.com', 'NSBM', 2),
('Ranil Wickramasinghe', '603181028v', '922, 1st Lane, Colombo', 0771729281, 'ranil@unp.com', 'UOC', 3),
('Sajith Premadasa', '683481098v', '21, Flowers Street, Hambanthota', 077172281, 'sajith@sjb.com', 'UOSJ', 18),
('Harin Fernando', '723181098v', '1, Lovers Street, Badulla', 0771238181, 'harin@sjb.com', 'UOSJ', 18);

ALTER TABLE Students
ADD CONSTRAINT FK_Room_Id
FOREIGN KEY (Room_Id) REFERENCES Rooms(Id);

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

SELECT Room_Count, Reserved FROM 
(SELECT COUNT(Id)  AS Room_Count FROM Rooms) As Room_Count UNION
(SELECT COUNT(DISTINCT Room_Id) AS Reserved_Room_Count FROM Students) As Reserved)  x

