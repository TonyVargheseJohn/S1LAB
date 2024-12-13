const connection = require('./database.js');

const selectDataQuery = 'SELECT * FROM college';

connection.query(selectDataQuery, (err, results) => {
  if (err) {
    console.error('Error selecting data:', err);
    return;
  }
  console.log('Data retrieved from "users" table:');
  console.log(results);
});