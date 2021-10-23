--Rooms Dashboard main table
CREATE VIEW Building_Rooms AS
SELECT b.Name,
    ISNULL((SELECT COUNT(r.ID) FROM Rooms r WHERE r.Building_Id = b.Id AND r.Room_Type = 'S'), 0) AS 'Single Total',
    ISNULL((SELECT COUNT(x.ID) FROM Rooms x WHERE x.Building_Id = b.Id AND x.Room_Type = 'D'), 0) AS 'Double Total',
    ISNULL((SELECT y.Free FROM(
        SELECT COUNT(x.Room_Id) AS 'Free',x.Room_Type, x.Building_Id FROM (
            SELECT DISTINCT s.Room_Id, r.Room_Type, r.Building_Id FROM Students s JOIN Rooms r ON s.Room_Id = r.Id)x
            GROUP BY x.Building_Id, x.Room_Type
        )y  WHERE y.Building_Id = b.Id AND y.Room_Type = 'S'), 0) AS 'Rented Single',
    ISNULL((SELECT y.Free FROM(
        SELECT COUNT(x.Room_Id) AS 'Free',x.Room_Type, x.Building_Id FROM (
            SELECT DISTINCT s.Room_Id, r.Room_Type, r.Building_Id FROM Students s JOIN Rooms r ON s.Room_Id = r.Id)x
            GROUP BY x.Building_Id, x.Room_Type
        )y  WHERE y.Building_Id = b.Id AND y.Room_Type = 'D'), 0) AS 'Rented Double'
FROM Buildings b;

SELECT * FROM Building_Rooms;