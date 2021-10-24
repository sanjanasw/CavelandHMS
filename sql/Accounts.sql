CREATE TABLE Accounts(
     Id INT PRIMARY KEY IDENTITY(1,1),
     Student_Id INT NOT NULL,
     User_Id INT NOT NULL,
     Paid_On DATETIME DEFAULT CURRENT_TIMESTAMP
);

ALTER TABLE Accounts
ADD CONSTRAINT FK_Student_Id
FOREIGN KEY (Student_Id) REFERENCES Students(Id);

ALTER TABLE Accounts
ADD CONSTRAINT FK_User_Id
FOREIGN KEY (User_Id) REFERENCES Users(Id);

INSERT INTO Accounts(Student_Id, User_Id, Paid_On)
VALUES
(1,1,'2021/10/04'),
(2,1,'2021/08/05'),
(3,1,'2021/08/04'),
(4,1,'2021/08/05'),
(5,1,'2021/08/04'),
(6,1,'2021/08/05'),
(7,1,'2021/08/05'),
(1,1,'2021/09/04'),
(2,1,'2021/09/05'),
(3,1,'2021/09/04'),
(4,1,'2021/09/05'),
(5,1,'2021/09/04'),
(6,1,'2021/09/05'),
(7,1,'2021/09/05'),
(2,1,'2021/10/05'),
(5,1,'2021/10/04');

SELECT s.Name,
    (SELECT
        (SELECT b.Name FROM Buildings b WHERE b.Id =  r.Building_Id)
    FROM Rooms r WHERE r.Id =  s.Room_Id) AS Building,
    CASE 
        WHEN x.Paid_On IS NULL
            THEN 'NOT'
            ELSE 'PAID' END AS 'STATUS'
FROM Students s
    LEFT JOIN
        (SELECT * FROM Accounts a
        WHERE  a.Paid_On  BETWEEN  '2021-10-01' AND '2021-11-01'
        ) x ON s.Id = x.Student_Id;


SELECT * FROM Students;
SELECT * FROM Accounts;
SELECT * FROM Rooms;
SELECT * FROM Buildings;


CREATE PROCEDURE GetPaymentStatus
@FromDate DATETIME,
@ToDate DATETIME
AS
SELECT s.Name,
    (SELECT
        (SELECT b.Name FROM Buildings b WHERE b.Id =  r.Building_Id)
    FROM Rooms r WHERE r.Id =  s.Room_Id) AS Building,
    CASE 
        WHEN x.Paid_On IS NULL
            THEN 'NOT'
            ELSE 'PAID' END AS 'STATUS'
FROM Students s
    LEFT JOIN
        (SELECT * FROM Accounts a
        WHERE  a.Paid_On  BETWEEN  @FromDate AND @ToDate
        ) x ON s.Id = x.Student_Id
GO

EXEC GetPaymentStatus @FromDate = '2021-10-01' , @ToDate = '2021-11-01'