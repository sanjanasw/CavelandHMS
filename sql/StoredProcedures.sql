--New Admission
CREATE PROCEDURE newAdmission
@Name VARCHAR(100),
@Nic_No VARCHAR(12),
@Address VARCHAR(250),
@Tp INT,
@Email VARCHAR(100),
@University VARCHAR(80),
@Room_Id INT
AS
	INSERT INTO Students(Name, Nic_No, Address, Tp, Email, University, Room_Id) VALUES (@Name, @NiC_No, @Address, @Tp, @Email, @University, @Room_Id)
GO

EXEC newAdmission @Name = 'Iraj Weerarathne', @Nic_No = '773181098v', @Address = '178, Middle Street, Homagama.',@Tp = 0771119181, @Email = 'iraj@noize.com', @University = 'NSBM', @Room_Id = 4;


--Get Payment Status
CREATE PROCEDURE GetPaymentStatus
@FromDate DATETIME,
@ToDate DATETIME
AS
SELECT s.Name, s.Room_Id,
    (SELECT
        (SELECT b.Name FROM Buildings b WHERE b.Id =  r.Building_Id)
    FROM Rooms r WHERE r.Id =  s.Room_Id) AS Building,
     s.Tp, s.University,
    CASE 
        WHEN x.Paid_On IS NULL
            THEN 'NOT PAID'
            ELSE 'PAID' END AS 'STATUS'
FROM Students s
    LEFT JOIN
        (SELECT * FROM Accounts a
        WHERE  a.Paid_On  BETWEEN  @FromDate AND @ToDate
        ) x ON s.Id = x.Student_Id
GO

EXEC GetPaymentStatus @FromDate = '2021-10-01' , @ToDate = '2021-11-01'

--Get Revenue Data;
CREATE PROCEDURE GetRevenueData
AS
    SELECT MONTH(f.Paid_On) AS Month,  SUM(f.Rental) AS Rental FROM (
        SELECT  x.Paid_On,
        (SELECT r.Rental FROM Rooms r WHERE r.Id = s.Room_Id) AS Rental
        FROM (SELECT st.id, st.Room_Id,
                ROW_NUMBER() OVER (partition by st.Room_Id order by st.Room_Id desc)
                    AS Ro_No FROM Students st) s
            LEFT JOIN
                (SELECT a.Student_Id, a.Paid_On FROM Accounts a
                ) x ON s.Id = x.Student_Id WHERE s.Ro_No = 1 
    )f GROUP BY MONTH(f.Paid_On)
GO

EXEC GetRevenueData

--Add New Rooms
CREATE PROCEDURE addnewrooms
    @Building_Id INT,
    @Room_Type CHAR,
    @Rental FLOAT,
    @Rooms_Count INT,
    @Counter INT
AS
    SET @Counter = 1
    WHILE ( @Counter <= @Rooms_Count)
    BEGIN
        INSERT INTO rooms(Building_Id, Room_Type, Rental) VALUES
        (@Building_Id, @Room_Type, @Rental)
        SET @Counter  = @Counter  + 1
    END
GO

EXEC addnewrooms @Building_ID = 1, @Room_Type = 'S', @Rental = 50000.00, @Rooms_Count = 2 , @Counter = 1;

--CollectPayment
CREATE PROCEDURE CollectPayment
@st INT,
@id INT
AS
  INSERT INTO Accounts(Student_Id, User_Id) VALUES (@st, @Id);
GO

EXEC CollectPayment @st = 1, @id = 1;

--Find Student
Create PROCEDURE FindStudent
@Id INT
AS
  SELECT *, (SELECT Name FROM Buildings WHERE Id = (SELECT Building_Id From Rooms WHERE Id = Room_Id)) AS Building FROM Students WHERE Id = @Id;
GO

EXEC FindStudent @Id = 1;


--New User
CREATE PROCEDURE newUser
    @Name VARCHAR(100),
    @Pass VARCHAR(20),
    @Nic_No VARCHAR(12),
    @Address VARCHAR(250),
    @Tp INT,
    @Email VARCHAR(100),
    @Salary INT
AS
    INSERT INTO Users(UserName, [Password], Nic_No, [Address], Tp, Email, Salary, User_Role) VALUES (@Name, @Pass, @NiC_No, @Address, @Tp, @Email, @Salary, 1)
GO

EXEC newUser @Name = 'kasun', @Pass = 'kasun', @Nic_No = '953571089v', @Address = '192, middle steet. colombo', @Tp = 07718837421, @Email = 'kasun@gmail.com', @Salary = 45000;
