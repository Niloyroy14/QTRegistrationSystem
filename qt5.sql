-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 14, 2025 at 01:18 PM
-- Server version: 10.4.17-MariaDB
-- PHP Version: 8.0.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `qt5`
--

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `phone` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `image` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `username`, `password`, `phone`, `email`, `image`) VALUES
(2, 'Niloy', '12345', '01727532825', 'niloyroy3@gmail.com', 'D:/QT Exersice/build-NewRegistrationSystem-Desktop_Qt_5_12_2_MinGW_32_bit-Debug/debug/images/20230823_214830_2403062727_2IMG_o3559e.jpg'),
(3, 'Rubel Mia', '12345', '01727532825', 'niloyroy3@gmail.com', NULL),
(4, 'Rafa', '12345', '01727532825', 'Rafa@gmail.com', 'D:/QT Exersice/build-NewRegistrationSystem-Desktop_Qt_5_12_2_MinGW_32_bit-Debug/debug/images/20230713_114727_741669936_324630888_979206053484592_2688227334525953649_n.jpg'),
(5, 'Mim', '12345', '01684945328', 'mim@gmail.com', NULL),
(6, 'ani', '12345', '01727532825', 'ani@gmail.com', NULL),
(7, 'Nishat', '12345', '01673245673', 'nishat@gmail.com', NULL),
(8, 'Niloy', '12345', '01727532825', 'niloyroy3@gmail.com', NULL);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
