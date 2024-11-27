-- CREATE TABLE users (
--   id INTEGER PRIMARY KEY,
--   occupation TEXT NOT NULL,
--   name TEXT NOT NULL,
--   username TEXT NOT NULL,
--   password TEXT NOT NULL
-- );

-- CREATE TABLE IF NOT EXISTS patients_list (
--     id INTEGER PRIMARY KEY NOT NULL,
--     name TEXT NOT NULL,
--     dob DATE NOT NULL,
--     study_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
--     doctor_id INTEGER NOT NULL,  -- Foreign key to reference the doctor
--     blood_type TEXT,
--     medical_conditions TEXT,
--     medications TEXT,
--     hc_measurement REAL,
--     bpd_measurement REAL, 
--     ofd_measurement REAL, 
--     fl_measurement REAL, 
--     hc_image BLOB,  -- To store ultrasound images
--     fl_image BLOB,
--     FOREIGN KEY (doctor_id) REFERENCES users (id)  -- Reference to the doctor
-- );

-- INSERT INTO patients_list (
--     id, name, dob, study_date, doctor_id, blood_type, medical_conditions, medications
-- )
-- VALUES 
--     (1100, 'Asmaa Marwan', '1990-02-14', CURRENT_TIMESTAMP, 1, 'A+', 'None', 'None'),
--     (1200, 'Sarah Badr', '1987-06-23', CURRENT_TIMESTAMP, 1, 'O-', 'Gestational Diabetes', 'Insulin'),
--     (1300, 'Eman Darr', '1993-11-12', CURRENT_TIMESTAMP, 1, 'B+', 'Diabetes', 'Metformin'),
--     (1400, 'Sofia Waseem', '1989-01-05', CURRENT_TIMESTAMP, 1, 'O+', 'Asthma', 'Inhaler'),
--     (1500, 'Afnan Muhammed', '1995-08-15', CURRENT_TIMESTAMP, 1, 'AB-', 'Thyroid Issues', 'Levothyroxine'),

--     (1600, 'Esraa Thamer', '1991-03-09', CURRENT_TIMESTAMP, 2, 'A-', 'Anemia', 'Iron Supplements'),
--     (1700, 'Arjwan Aymen', '1988-10-21', CURRENT_TIMESTAMP, 2, 'B-', 'None', 'None'),
--     (1800, 'Marwa Gasim', '1994-04-17', CURRENT_TIMESTAMP, 2, 'A+', 'None', 'None'),
--     (1900, 'Najwa Muhaned', '1996-06-30', CURRENT_TIMESTAMP, 2, 'O-', 'Gestational Diabetes', 'Insulin'),
--     (2100, 'Raghad Hatem', '1992-12-05', CURRENT_TIMESTAMP, 2, 'AB+', 'Hypertension', 'Amlodipine'),

--     (2200, 'Ghada Saud', '1990-07-19', CURRENT_TIMESTAMP, 3, 'O+', 'Thyroid Issues', 'Levothyroxine'),
--     (2300, 'Haneen Waleed', '1997-01-22', CURRENT_TIMESTAMP, 3, 'B-', 'None', 'None'),
--     (2400, 'Ghalia Faisal', '1986-03-13', CURRENT_TIMESTAMP, 3, 'A-', 'Asthma', 'Inhaler'),
--     (2500, 'Bayan Talal', '1989-08-25', CURRENT_TIMESTAMP, 3, 'O+', 'Gestational Hypertension', 'Hydralazine');



-- INSERT INTO users (occupation, name, username, password) 
-- VALUES ('sonographer', 'Khalid Khan', 'drK123', 'k123'), ('sonographer', 'Sara Salem', 'drS123', 's123'), 
-- ('sonographer', 'Rawan Rayan', 'drR123', 'r123'), ('nurse', 'Maram Malik', 'drM123', 'm123');


-- adding columns: ALTER TABLE users ADD COLUMN column_name TEXT NOT NULL;
-- DROP TABLE patients_list;
-- adding data to the table: INSERT INTO users (id, name, username, password) VALUES ()

-- DELETE FROM users WHERE id == 2;

-- INSERT INTO users (occupation, name, username, password)
-- VALUES ('nurse', 'Rayan M', 'ER_RM123', 'rm12345'), ('patient', 'Abrar Khalid', 'AbrarKhalid', 'abrar123');

-- updating data: UPDATE users SET occupation = 'nurse' WHERE id = 1;

-- SELECT * FROM patients_list;
-- ALTER TABLE patients_list ADD COLUMN seg_fl_image BLOB;