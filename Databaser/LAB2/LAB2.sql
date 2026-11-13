CREATE DATABASE IF NOT EXISTS LAB2;
USE LAB2;

CREATE TABLE Customer(
    customer_id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    name VARCHAR(50) NOT NULL,
    type_of_customer VARCHAR(50),
    street VARCHAR(50),
    city VARCHAR(50),
    state VARCHAR(50),
    zip VARCHAR(50),
    fax_nr VARCHAR(20),
    phone_nr VARCHAR(20)
);

CREATE TABLE Employees(
    employee_id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    hire_date VARCHAR(10) NOT NULL,
    address VARCHAR(50) NOT NULL,
    city VARCHAR(50),
    state VARCHAR(50),
    zip VARCHAR(50),
    home_phone VARCHAR(20),
    education VARCHAR(20)

);

CREATE TABLE Pets(
    pet_id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    pet_name VARCHAR(50) NOT NULL,
    type_of_animal VARCHAR(50) NOT NULL,
    breed VARCHAR(50),
    birth_date DATE NOT NULL,
    gender VARCHAR(6),
    c_id INT NOT NULL,
    FOREIGN KEY (c_id) REFERENCES Customer(customer_id)
);
CREATE TABLE Service(
    service_id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    description VARCHAR(500),
    price INT
);

CREATE TABLE Visit(
    visit_id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    Date DATE NOT NULL,
    notes VARCHAR(1000),
    p_id INT NOT NULL,
    emp_id INT NOT NULL,
    FOREIGN KEY(p_id) REFERENCES Pets(pet_id),
    FOREIGN KEY(emp_id) REFERENCES Employees(employee_id)
);

CREATE TABLE Treatment(
    v_id INT NOT NULL,
    s_id INT NOT NULL,
    price INT,
    notes VARCHAR(1000),
    PRIMARY KEY (v_id, s_id),
    FOREIGN KEY(v_id) REFERENCES Visit(visit_id),
    FOREIGN KEY (s_id) REFERENCES Service(service_id)
);
CREATE TABLE Employee_Service(
    e_id INT NOT NULL,
    s_id INT NOT NULL,
    PRIMARY KEY (e_id, s_id),
    FOREIGN KEY (e_id) REFERENCES Employees(employee_id),
    FOREIGN KEY (s_id) REFERENCES Service(service_id)
);

