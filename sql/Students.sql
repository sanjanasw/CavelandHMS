--trigger for age and gender
CREATE trigger getage
ON Students
AFTER INSERT
AS
	BEGIN
		DECLARE @nic VARCHAR (12)
		SELECT @nic = Nic_No FROM inserted

		DECLARE @len INT
		DECLARE @year INT
		DECLARE @daytext INT
		DECLARE @gen CHAR
		DECLARE @age INT
		DECLARE @cyear INT

		SET @len = LEN(@nic)

		IF @len = 10
		BEGIN
			SET @year = cast('19' + SUBSTRING(@nic, 1, 2) AS INT)
			SET @daytext = cast(SUBSTRING(@nic, 3, 3) AS  INT)
		END
		ELSE
		BEGIN
			SET @year = cast(SUBSTRING(@nic, 1, 4) AS INT)
			SET @daytext = cast(SUBSTRING(@nic, 5, 3) AS INT)
		END

		IF @daytext > 500
		BEGIN
			SET @gen = 'F'
		END
		ELSE
		BEGIN
			SET @gen = 'M'
		END

		SET @cyear = YEAR(GETDATE())
		SET @age = @cyear - @year

		UPDATE Students SET Age = @age, Gender = @gen WHERE Nic_No = @nic;

	end
go


CREATE TABLE Students (
    Id INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(100) NOT NULL,
    Nic_No VARCHAR(12) UNIQUE,
    Address VARCHAR(250) NOT NULL,
    Tp INT NOT NULL,
    Email VARCHAR(100) NOT NULL,
    University VARCHAR(80),
    Room_Id INT NOT NULL,
    Gender CHAR,
    Age INT,
);


INSERT INTO Students(Name, Nic_No, Address, TP, Email, University, Room_Id) VALUES
('Mahinda Rajapaksha', '583181098v', '1, Madamulana Rd, Hambanthota', 0771729181, 'mahinda@slpp.com', 'NSBM', 1),
('Gotabaya Rajapaksha', '653181018v', '2, Madamulana Rd, Hambanthota', 0771723481, 'gota@slpp.com', 'NSBM', 2),
('Ranil Wickramasinghe', '603181028v', '922, 1st Lane, Colombo', 0771729281, 'ranil@unp.com', 'UOC', 3),
('Sajith Premadasa', '683481098v', '21, Flowers Street, Hambanthota', 077172281, 'sajith@sjb.com', 'UOSJ', 18),
('Harin Fernando', '723181098v', '1, Lovers Street, Badulla', 0771238181, 'harin@sjb.com', 'UOSJ', 18),
('Jalani Premadasa', '747891098v', '21, Flowers Street, Hambanthota', 0778729181, 'angeljalani@gmail.com', 'UOSJ', 46),
('Shirani Rajapaksha', '627891098v', '1, Madamulana Rd Hambanthota', 0719849181, 'shiranthiroxx@gmail.com', 'NSBM', 47);

ALTER TABLE Students
ADD CONSTRAINT FK_Room_Id
FOREIGN KEY (Room_Id) REFERENCES Rooms(Id);


SELECT * FROM Students