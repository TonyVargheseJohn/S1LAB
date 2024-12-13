const connection = require('./database.js');

// Create a table
const createTableQuery = `
  CREATE TABLE college (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100),
    age INT
  );
`;

connection.query(createTableQuery, (err, results) => {
  if (err) {
    console.error('Error creating table:', err);
    return;
  }
  console.log('Table "college" created successfully');
});
const insertDataQuery = `
  INSERT INTO college (name, email, age)
  VALUES ('John Doe', 'john.doe@example.com', 30)
`;

connection.query(insertDataQuery, (err, results) => {
  if (err) {
    console.error('Error inserting data:', err);
    return;
  }
  console.log('Data inserted into the "users" table');
});

const updateDataQuery = `
  UPDATE college
  SET age = 31
  WHERE name = 'John Doe'
`;

connection.query(updateDataQuery, (err, results) => {
  if (err) {
    console.error('Error updating data:', err);
    return;
  }
  console.log('Data updated in the "users" table');
});

const selectDataQuery = 'SELECT * FROM college';

connection.query(selectDataQuery, (err, results) => {
  if (err) {
    console.error('Error selecting data:', err);
    return;
  }
  console.log('Data retrieved from "users" table:');
  console.log(results);
});

