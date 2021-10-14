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