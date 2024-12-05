-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 05, 2024 at 01:50 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `university`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `adminID` int(11) NOT NULL,
  `userID` int(11) NOT NULL,
  `permissions` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`adminID`, `userID`, `permissions`) VALUES
(1, 3, 'Full Access'),
(2, 5, 'Full Access'),
(3, 5, 'Full Access');

-- --------------------------------------------------------

--
-- Table structure for table `course`
--

CREATE TABLE `course` (
  `courseID` int(11) NOT NULL,
  `courseName` varchar(255) DEFAULT NULL,
  `courseDescription` varchar(1000) DEFAULT NULL,
  `credits` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `course`
--

INSERT INTO `course` (`courseID`, `courseName`, `courseDescription`, `credits`) VALUES
(1, 'Artificial Intelligence', 'A course on the fundamentals of artificial intelligence, including search algorithms and machine learning.', 3),
(2, 'Mathematics', 'A course that covers the concepts of relational databases and SQL.', 3),
(3, 'Computer Science', 'An intermediate course focusing on algorithms and data structures.', 4),
(4, 'Business Admin', 'Business is good sua bi', 2);

-- --------------------------------------------------------

--
-- Table structure for table `coursematerials`
--

CREATE TABLE `coursematerials` (
  `materialID` int(11) NOT NULL,
  `courseID` int(11) DEFAULT NULL,
  `materialType` varchar(50) DEFAULT NULL,
  `materialTitle` varchar(255) DEFAULT NULL,
  `materialPath` varchar(500) DEFAULT NULL,
  `uploadDate` datetime DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `coursematerials`
--

INSERT INTO `coursematerials` (`materialID`, `courseID`, `materialType`, `materialTitle`, `materialPath`, `uploadDate`) VALUES
(1, 1, 'Textbook ', 'Intro To AI', 'https://www.coursera.org/learn/introduction-to-ai', '2024-12-03 21:29:59'),
(2, 3, 'Textbook', 'Intro to C++', 'https://www.w3schools.com/cpp/cpp_intro.asp', '2024-12-03 21:32:33');

-- --------------------------------------------------------

--
-- Table structure for table `enrollments`
--

CREATE TABLE `enrollments` (
  `enrollmentID` int(11) NOT NULL,
  `studentID` int(11) NOT NULL,
  `courseID` int(11) NOT NULL,
  `enrollmentDate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `enrollments`
--

INSERT INTO `enrollments` (`enrollmentID`, `studentID`, `courseID`, `enrollmentDate`) VALUES
(1, 1, 1, '2024-08-01'),
(2, 1, 3, '2024-08-01'),
(3, 2, 2, '2024-08-01'),
(5, 1, 2, '2024-12-03'),
(6, 1, 3, '2024-12-03'),
(7, 1, 4, '2024-12-03'),
(8, 1, 2, '2024-12-05');

-- --------------------------------------------------------

--
-- Table structure for table `faculty`
--

CREATE TABLE `faculty` (
  `facultyID` int(11) NOT NULL,
  `userID` int(11) NOT NULL,
  `department` enum('Computer Science','Mathematics','Artificial Intelligence') NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `faculty`
--

INSERT INTO `faculty` (`facultyID`, `userID`, `department`) VALUES
(1, 2, 'Computer Science'),
(20, 20, 'Mathematics'),
(100, 100, 'Computer Science');

-- --------------------------------------------------------

--
-- Table structure for table `grades`
--

CREATE TABLE `grades` (
  `gradeID` int(11) NOT NULL,
  `studentID` int(11) NOT NULL,
  `courseID` int(11) NOT NULL,
  `grade` char(1) NOT NULL,
  `semester` int(11) DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `grades`
--

INSERT INTO `grades` (`gradeID`, `studentID`, `courseID`, `grade`, `semester`) VALUES
(1, 1, 1, 'A', 1),
(2, 1, 3, 'B', 1),
(3, 2, 2, 'A', 1),
(6, 1, 2, 'A', 1),
(7, 1, 2, 'A', 1),
(8, 1, 2, 'C', 1);

-- --------------------------------------------------------

--
-- Table structure for table `payments`
--

CREATE TABLE `payments` (
  `paymentID` int(11) NOT NULL,
  `studentID` int(11) NOT NULL,
  `amount` decimal(10,2) NOT NULL,
  `paymentDate` date NOT NULL,
  `paymentMethod` enum('card','cash','momo') NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `payments`
--

INSERT INTO `payments` (`paymentID`, `studentID`, `amount`, `paymentDate`, `paymentMethod`) VALUES
(1, 1, 500.00, '2024-08-10', 'card'),
(2, 2, 600.00, '2024-08-10', 'card'),
(4, 1, 0.00, '2024-12-03', ''),
(5, 1, 0.00, '2024-12-03', 'momo'),
(6, 1, 50000.00, '2024-12-03', 'cash'),
(7, 3, 50000.00, '2024-12-03', 'cash'),
(9, 1, 500.00, '2024-12-03', 'momo'),
(10, 1, 700.00, '2024-12-05', 'cash'),
(11, 1, 500.00, '2024-12-05', 'cash');

-- --------------------------------------------------------

--
-- Table structure for table `role`
--

CREATE TABLE `role` (
  `roleID` int(11) NOT NULL,
  `Role` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `role`
--

INSERT INTO `role` (`roleID`, `Role`) VALUES
(1, 'admin'),
(2, 'faculty'),
(3, 'student');

-- --------------------------------------------------------

--
-- Table structure for table `schedule`
--

CREATE TABLE `schedule` (
  `ScheduleID` int(11) NOT NULL,
  `StudentID` int(11) DEFAULT NULL,
  `CourseID` int(11) DEFAULT NULL,
  `DayOfTheWeek` enum('Monday','Tuesday','Wednesday','Thursday','Friday','Saturday','Sunday') NOT NULL,
  `StartTime` time NOT NULL,
  `EndTime` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `schedule`
--

INSERT INTO `schedule` (`ScheduleID`, `StudentID`, `CourseID`, `DayOfTheWeek`, `StartTime`, `EndTime`) VALUES
(7, 1, 1, 'Monday', '09:00:00', '11:00:00'),
(8, 1, 2, 'Wednesday', '10:00:00', '12:00:00'),
(9, 1, 3, 'Friday', '14:00:00', '16:00:00');

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

CREATE TABLE `student` (
  `studentID` int(11) NOT NULL,
  `userID` int(11) NOT NULL,
  `major` enum('Computer Science','Mathematics','Artificial Intelligence') NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`studentID`, `userID`, `major`) VALUES
(4, 4, 'Mathematics'),
(7, 7, 'Mathematics'),
(13, 10, 'Computer Science'),
(16, 11, 'Computer Science'),
(21, 201, ''),
(22, 201, '');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `userID` int(11) NOT NULL,
  `firstName` varchar(100) NOT NULL,
  `lastName` varchar(100) NOT NULL,
  `email` varchar(100) NOT NULL,
  `password` varchar(255) NOT NULL,
  `roleID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`userID`, `firstName`, `lastName`, `email`, `password`, `roleID`) VALUES
(1, 'Nellie', 'Dweben', 'NellieDweben@gmail.com', 'studentpassword', 3),
(2, 'Kwesi', 'Agya', 'turing@cs.edu', 'password123', 2),
(4, 'Reece', 'James', 'ReeceJames@gmail.com', '4pY1IU8O', 3),
(5, 'fpapa', 'Badu', 'raybadu10@gmail.com', '12345', 1),
(7, 'Michael', 'MorningStar', 'MichaelMorningStar@gmail.com', 'kHPQFYVY', 3),
(8, 'Cristian', 'Turing', 'CristianTuring@gmail.com', 'y6al54if', 3),
(10, 'Nana', 'Dwamena', 'NanaDwamena@gmail.com', 'HhCF9K6s', 3),
(11, 'Papa', 'Diame', 'PapaDiame@gmail.com', 'tdbPm4Qs', 3),
(12, 'John', 'Doe', 'johndoe@example.com', 'studentpassword', 3),
(20, 'Johnny', '', 'john@gmail.com', 'asdfghjkl', NULL),
(100, 'Victor', '', 'torinoo@gmail.com', 'torino423', NULL),
(201, 'Steven', 'Roberts', 'StevenRoberts@gmail.com', 'wld99nqK', 3);

--
-- Triggers `users`
--
DELIMITER $$
CREATE TRIGGER `after_user_insert` AFTER INSERT ON `users` FOR EACH ROW BEGIN
    IF NEW.roleID = 1 THEN
        INSERT INTO admin (userID, permissions) VALUES (NEW.userID, 'Full Access');
    ELSEIF NEW.roleID = 2 THEN
        INSERT INTO faculty (userID, department) VALUES (NEW.userID, 'Unknown Department');
    ELSEIF NEW.roleID = 3 THEN
        INSERT INTO student (userID, major) VALUES (NEW.userID, 'Undecided');
    END IF;
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `after_user_insert_admin` AFTER INSERT ON `users` FOR EACH ROW BEGIN
    IF NEW.roleID = 1 THEN
        INSERT INTO `admin` (`userID`, `permissions`)
        VALUES (NEW.userID, 'Full Access');
    END IF;
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `after_user_insert_faculty` AFTER INSERT ON `users` FOR EACH ROW BEGIN
    IF NEW.roleID = 2 THEN
        INSERT INTO `faculty` (`userID`, `department`)
        VALUES (NEW.userID, 'Unknown Department');
    END IF;
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `after_user_insert_student` AFTER INSERT ON `users` FOR EACH ROW BEGIN
    IF NEW.roleID = 3 THEN
        INSERT INTO `student` (`userID`, `major`)
        VALUES (NEW.userID, 'Undecided');
    END IF;
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `after_user_role_update` AFTER UPDATE ON `users` FOR EACH ROW BEGIN
    -- Remove from previous role table if role changes
    IF OLD.roleID <> NEW.roleID THEN
        CASE OLD.roleID
            WHEN 1 THEN
                DELETE FROM admin WHERE userID = OLD.userID;
            WHEN 2 THEN
                DELETE FROM faculty WHERE userID = OLD.userID;
            WHEN 3 THEN
                DELETE FROM student WHERE userID = OLD.userID;
        END CASE;

        -- Add to new role table
        CASE NEW.roleID
            WHEN 1 THEN
                INSERT INTO admin (userID, permissions) VALUES (NEW.userID, 'Full Access');
            WHEN 2 THEN
                INSERT INTO faculty (userID, department) VALUES (NEW.userID, 'Unknown Department');
            WHEN 3 THEN
                INSERT INTO student (userID, major) VALUES (NEW.userID, 'Undecided');
        END CASE;
    END IF;
END
$$
DELIMITER ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`adminID`),
  ADD KEY `userID` (`userID`);

--
-- Indexes for table `course`
--
ALTER TABLE `course`
  ADD PRIMARY KEY (`courseID`);

--
-- Indexes for table `coursematerials`
--
ALTER TABLE `coursematerials`
  ADD PRIMARY KEY (`materialID`),
  ADD KEY `courseID` (`courseID`);

--
-- Indexes for table `enrollments`
--
ALTER TABLE `enrollments`
  ADD PRIMARY KEY (`enrollmentID`),
  ADD KEY `studentID` (`studentID`),
  ADD KEY `courseID` (`courseID`);

--
-- Indexes for table `faculty`
--
ALTER TABLE `faculty`
  ADD PRIMARY KEY (`facultyID`),
  ADD KEY `userID` (`userID`);

--
-- Indexes for table `grades`
--
ALTER TABLE `grades`
  ADD PRIMARY KEY (`gradeID`),
  ADD KEY `studentID` (`studentID`),
  ADD KEY `courseID` (`courseID`);

--
-- Indexes for table `payments`
--
ALTER TABLE `payments`
  ADD PRIMARY KEY (`paymentID`),
  ADD KEY `studentID` (`studentID`);

--
-- Indexes for table `role`
--
ALTER TABLE `role`
  ADD PRIMARY KEY (`roleID`),
  ADD UNIQUE KEY `Role` (`Role`);

--
-- Indexes for table `schedule`
--
ALTER TABLE `schedule`
  ADD PRIMARY KEY (`ScheduleID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `student`
--
ALTER TABLE `student`
  ADD PRIMARY KEY (`studentID`),
  ADD KEY `userID` (`userID`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`userID`),
  ADD UNIQUE KEY `email` (`email`),
  ADD KEY `fk_user_role` (`roleID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin`
--
ALTER TABLE `admin`
  MODIFY `adminID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `course`
--
ALTER TABLE `course`
  MODIFY `courseID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `coursematerials`
--
ALTER TABLE `coursematerials`
  MODIFY `materialID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `enrollments`
--
ALTER TABLE `enrollments`
  MODIFY `enrollmentID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `faculty`
--
ALTER TABLE `faculty`
  MODIFY `facultyID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=201;

--
-- AUTO_INCREMENT for table `grades`
--
ALTER TABLE `grades`
  MODIFY `gradeID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `payments`
--
ALTER TABLE `payments`
  MODIFY `paymentID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT for table `role`
--
ALTER TABLE `role`
  MODIFY `roleID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `schedule`
--
ALTER TABLE `schedule`
  MODIFY `ScheduleID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `student`
--
ALTER TABLE `student`
  MODIFY `studentID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `userID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=202;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
