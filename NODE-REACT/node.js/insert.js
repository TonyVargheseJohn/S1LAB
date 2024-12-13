const insertDataQuery = `
  INSERT INTO college (name, email, age)
  VALUES ('John Doe', 'john.doe@example.com', 30)
`;

connection.query(insertDataQuery, (err, results) => {
  if (err) {
    console.error('Error inserting data:', err);
    return;
  }
  console.log('Data inserted into the "college" table');
});
