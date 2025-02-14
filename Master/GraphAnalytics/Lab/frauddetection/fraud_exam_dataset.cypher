
//run it one by one
CREATE CONSTRAINT FOR (s:Email) REQUIRE (s.value) IS UNIQUE;
CREATE CONSTRAINT FOR (s:PhoneNumber) REQUIRE (s.value) IS UNIQUE;
CREATE CONSTRAINT FOR (s:WorkAddress) REQUIRE (s.value) IS UNIQUE;
CREATE CONSTRAINT FOR (s:HealthInsurance) REQUIRE (s.value) IS UNIQUE;
CREATE CONSTRAINT FOR (s:IPIstance) REQUIRE (s.id) IS UNIQUE;



//run it all at once
CREATE (dave100:User {accountId: "30498230293", username: "dave100", email: "dave_001@mail.com", name:"Dave Ross", phone_number: "512-345-9593", work_address: "25 Cambridge Street - Lula, CA", health_insurance_ID:"038562"})
CREATE (elis_001:User {accountId: "49299276302", username: "elis_001", email: "wx456@tim.it", name:"Elis Ridge", phone_number: "580-548-1149", work_address: "4093 Crocks Road - Vers, OK"})
CREATE (charlie_X:User {accountId: "10232860293", username: "charlie_X", email: "jam@mail.com", name:"Charlie Taylor", phone_number: "580-262-8593", work_address: "4093 Crocks Road - Vers, OK", health_insurance_ID:"629078"})
CREATE (harry_0b:User {accountId: "21023804875", username: "harry_0b", email: "wx456@tim.it", name:"Harry O'Connor", phone_number: "580-262-8593", work_address: "4985 Rose Avenue - MOUNT HOPE, WI", health_insurance_ID:"212765"})
CREATE (tomtom:User {accountId: "73102359500", username: "tomtom", email: "bob@google.com", name:"Thomas Antunez", phone_number: "352-588-92219", work_address: "2041 Bagwell Avenue - San Antonio, FL", health_insurance_ID:"142569"})
CREATE (evanstil:User {accountId: "987299276302", username: "evanstil", email: "45gng@uk.gov.com", name:"Evans Cooper", phone_number: "180-548-1149", work_address: "11 Cambridge Road - Los Angeles, CA"})
CREATE (wang79:User {accountId: "78922860293", username: "wang79", email: "wang79@mail.com", name:"Lee Wang", phone_number: "504-255-9593", work_address:  "45 Main Street - Los Angeles, CA", health_insurance_ID:"038562"})


CREATE (cc0:CreditCard {id: "196345"})
CREATE (ba0:BankAccount {id: "753159"})
CREATE (lo0:Loan {id: "642578"})
CREATE (dave100)-[:OWNS]->(cc0)
CREATE (dave100)-[:OWNS]->(ba0)
CREATE (dave100)-[:OWNS]->(lo0)

CREATE (cc1:CreditCard {id: "793922"})
CREATE (ba1:BankAccount {id: "896857"})
CREATE (lo1:Loan {id: "885398"})
CREATE (elis_001)-[:OWNS]->(cc1)
CREATE (elis_001)-[:OWNS]->(ba1)
CREATE (elis_001)-[:OWNS]->(lo1)

CREATE (cc2:CreditCard {id: "482513"})
CREATE (ba2:BankAccount {id: "305693"})
CREATE (charlie_X)-[:OWNS]->(cc2)
CREATE (charlie_X)-[:OWNS]->(ba2)

CREATE (cc3:CreditCard {id: "631264"})
CREATE (ba3:BankAccount {id: "591215"})
CREATE (lo3:Loan {id: "432775"})
CREATE (harry_0b)-[:OWNS]->(cc3)
CREATE (harry_0b)-[:OWNS]->(ba3)
CREATE (harry_0b)-[:OWNS]->(lo3)

CREATE (ba4:BankAccount {id: "377703"})
CREATE (lo4:Loan {id: "859923"})
CREATE (tomtom)-[:OWNS]->(ba4)
CREATE (tomtom)-[:OWNS]->(lo4)


CREATE (cc11:CreditCard {id: "792422"})
CREATE (ba11:BankAccount {id: "823857"})
CREATE (lo11:Loan {id: "565398"})
CREATE (evanstil)-[:OWNS]->(cc11)
CREATE (evanstil)-[:OWNS]->(ba11)
CREATE (evanstil)-[:OWNS]->(lo11)

CREATE (cc22:CreditCard {id: "487713"})
CREATE (ba22:BankAccount {id: "303293"})
CREATE (wang79)-[:OWNS]->(cc22)
CREATE (wang79)-[:OWNS]->(ba22)


MERGE (dave100Email:Email {value: "dave_001@mail.com"})
MERGE (dave100PhoneNumber:PhoneNumber {value: "512-345-9593"})
MERGE (dave100WorkAddress:WorkAddress {value: "25 Cambridge Street - Lula, CA"})
MERGE (dave100HealthInsurance:HealthInsurance {value: "038562"})
CREATE (dave100)-[:HAS_EMAIL]->(dave100Email)
CREATE (dave100)-[:HAS_PHONE_NUMBER]->(dave100PhoneNumber)
CREATE (dave100)-[:HAS_WORKADDRESS]->(dave100WorkAddress)
CREATE (dave100)-[:HAS_HEALTHINSURANCE]->(dave100HealthInsurance)


MERGE (elis_001Email:Email {value: "wx456@tim.it"})
MERGE (elis_001PhoneNumber:PhoneNumber {value: "580-548-1149"})
MERGE (elis_001WorkAddress:WorkAddress {value: "4093 Crocks Road - Vers, OK"})
CREATE (elis_001)-[:HAS_EMAIL]->(elis_001Email)
CREATE (elis_001)-[:HAS_PHONE_NUMBER]->(elis_001PhoneNumber)
CREATE (elis_001)-[:HAS_WORKADDRESS]->(elis_001WorkAddress)


MERGE (charlie_XEmail:Email {value: "jam@mail.com"})
MERGE (charlie_XPhoneNumber:PhoneNumber {value: "580-262-8593"})
MERGE (charlie_XWorkAddress:WorkAddress {value: "4093 Crocks Road - Vers, OK"})
MERGE (charlie_XHealthInsurance:HealthInsurance {value: "629078"})
CREATE (charlie_X)-[:HAS_EMAIL]->(charlie_XEmail)
CREATE (charlie_X)-[:HAS_PHONE_NUMBER]->(charlie_XPhoneNumber)
CREATE (charlie_X)-[:HAS_WORKADDRESS]->(charlie_XWorkAddress)
CREATE (charlie_X)-[:HAS_HEALTHINSURANCE]->(charlie_XHealthInsurance)


MERGE (harry_0bEmail:Email {value: "wx456@tim.it"})
MERGE (harry_0bPhoneNumber:PhoneNumber {value: "580-262-8593"})
MERGE (harry_0bWorkAddress:WorkAddress {value: "4985 Rose Avenue - MOUNT HOPE, WI"})
MERGE (harry_0bHealthInsurance:HealthInsurance {value: "212765"})
CREATE (harry_0b)-[:HAS_EMAIL]->(harry_0bEmail)
CREATE (harry_0b)-[:HAS_PHONE_NUMBER]->(harry_0bPhoneNumber)
CREATE (harry_0b)-[:HAS_WORKADDRESS]->(harry_0bWorkAddress)
CREATE (harry_0b)-[:HAS_HEALTHINSURANCE]->(harry_0bHealthInsurance)


MERGE (tomtomEmail:Email {value: "bob@google.com"})
MERGE (tomtomPhoneNumber:PhoneNumber {value: "352-588-92219"})
MERGE (tomtomWorkAddress:WorkAddress {value: "2041 Bagwell Avenue - San Antonio, FL"})
MERGE (tomtomHealthInsurance:HealthInsurance {value: "142569"})
CREATE (tomtom)-[:HAS_EMAIL]->(tomtomEmail)
CREATE (tomtom)-[:HAS_PHONE_NUMBER]->(tomtomPhoneNumber)
CREATE (tomtom)-[:HAS_WORKADDRESS]->(tomtomWorkAddress)
CREATE (tomtom)-[:HAS_HEALTHINSURANCE]->(tomtomHealthInsurance)

MERGE (evanstilEmail:Email {value: "45gng@uk.gov.com"})
MERGE (evanstilPhoneNumber:PhoneNumber {value: "180-548-1149"})
MERGE (evanstilWorkAddress:WorkAddress {value: "11 Cambridge Road - Los Angeles, CA"})
CREATE (evanstil)-[:HAS_EMAIL]->(evanstilEmail)
CREATE (evanstil)-[:HAS_PHONE_NUMBER]->(evanstilPhoneNumber)
CREATE (evanstil)-[:HAS_WORKADDRESS]->(evanstilWorkAddress)


MERGE (wang79Email:Email {value: "wang79@mail.com"})
MERGE (wang79PhoneNumber:PhoneNumber {value: "504-255-9593"})
MERGE (wang79WorkAddress:WorkAddress {value: "45 Main Street - Los Angeles, CA"})
MERGE (wang79HealthInsurance:HealthInsurance {value: "038562"})
CREATE (wang79)-[:HAS_EMAIL]->(wang79Email)
CREATE (wang79)-[:HAS_PHONE_NUMBER]->(wang79PhoneNumber)
CREATE (wang79)-[:HAS_WORKADDRESS]->(wang79WorkAddress)
CREATE (wang79)-[:HAS_HEALTHINSURANCE]->(wang79HealthInsurance)


CREATE (connection1:IPIstance {id:"246.184.50.48_2023-01-21", ip: "246.184.50.48", date: "2023-01-21"})
CREATE (connection2:IPIstance {id:"208.125.140.154_2023-01-19", ip: "208.125.140.154", date: "2023-01-19"})
CREATE (connection3:IPIstance {id:"74.248.71.234_2023-01-59", ip: "74.248.71.234", date: "2023-01-59"})
CREATE (harry_0b)-[:CONNECTED_FROM_workaddress]->(connection1)
CREATE (harry_0b)-[:CONNECTED_FROM_workaddress]->(connection3)
CREATE (tomtom)-[:CONNECTED_FROM_workaddress]->(connection1)
CREATE (charlie_X)-[:CONNECTED_FROM_workaddress]->(connection2)
CREATE (tomtom)-[:CONNECTED_FROM_workaddress]->(connection2)
CREATE (connection4:IPIstance {id:"246.185.50.48_2023-01-22", ip: "246.185.50.48", date: "2023-01-22"})
CREATE (connection5:IPIstance {id:"208.128.140.154_2023-01-10", ip: "208.128.140.154", date: "2023-01-10"})
CREATE (connection6:IPIstance {id:"74.249.71.234_2023-01-19", ip: "74.249.71.234", date: "2023-01-19"})
CREATE (evanstil)-[:CONNECTED_FROM_workaddress]->(connection4)
CREATE (wang79)-[:CONNECTED_FROM_workaddress]->(connection5)
CREATE (wang79)-[:CONNECTED_FROM_workaddress]->(connection6)
CREATE (tomtom)-[:CONNECTED_FROM_workaddress]->(connection6)
CREATE (tomtom)-[:CONNECTED_FROM_workaddress]->(connection4)

