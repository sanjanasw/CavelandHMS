SELECT * FROM Students;
SELECT * FROM Rooms;

CREATE PROCEDURE GetRevenueData
AS
    SELECT MONTH(f.Paid_On) AS Month SUM(f.Rental) AS Rental FROM (
        SELECT  x.Paid_On,
        (SELECT r.Rental FROM Rooms r WHERE r.Id = s.Room_Id) AS Rental
        FROM (SELECT st.id, st.Room_Id,
                ROW_NUMBER() OVER (partition by st.Room_Id order by st.Room_Id desc)
                    AS Ro_No FROM Students st) s
            LEFT JOIN
                (SELECT a.Student_Id, a.Paid_On FROM Accounts a
                ) x ON s.Id = x.Student_Id WHERE s.Ro_No = 1 
    )f GROUP BY MONTH(f.Paid_On)

EXEC GetRevenueData