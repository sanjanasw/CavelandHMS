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
