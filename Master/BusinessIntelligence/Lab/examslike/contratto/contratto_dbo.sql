---------------------------------------------------
-- 1) CREAZIONE DELLE TABELLE
---------------------------------------------------

-- Tabella CITTA
CREATE TABLE CITTA (
    CITTÀ VARCHAR(50) NOT NULL PRIMARY KEY,
    STATO VARCHAR(50) NOT NULL
);
GO

-- Tabella PERSONA
CREATE TABLE PERSONA (
    PERSONA VARCHAR(50) NOT NULL PRIMARY KEY,
    RESIDENZA VARCHAR(50) NOT NULL,
    TITOLO_DI_STUDIO VARCHAR(50),
    CONSTRAINT FK_PERSONA_CITTA 
        FOREIGN KEY (RESIDENZA) 
        REFERENCES CITTA (CITTÀ)
);
GO

-- Tabella ISTITUZIONE (con attributo DIRETTORE, FK verso PERSONA)
CREATE TABLE ISTITUZIONE (
    ISTITUZIONE VARCHAR(50) NOT NULL PRIMARY KEY,
    SEDE_LEGALE VARCHAR(50) NOT NULL,
    DIRETTORE VARCHAR(50) NOT NULL,
    CONSTRAINT FK_ISTITUZIONE_CITTA
        FOREIGN KEY (SEDE_LEGALE)
        REFERENCES CITTA (CITTÀ),
    CONSTRAINT FK_ISTITUZIONE_DIRETTORE
        FOREIGN KEY (DIRETTORE)
        REFERENCES PERSONA (PERSONA)
);
GO

-- Tabella CONVENZIONE
CREATE TABLE CONVENZIONE (
    CONVENZIONE VARCHAR(50) NOT NULL PRIMARY KEY,
    GENERE VARCHAR(50),
    ISTITUZIONE VARCHAR(50) NOT NULL,
    CONSTRAINT FK_CONVENZIONE_ISTITUZIONE
        FOREIGN KEY (ISTITUZIONE)
        REFERENCES ISTITUZIONE (ISTITUZIONE)
);
GO

-- Tabella CONTRATTO
CREATE TABLE CONTRATTO (
    CONVENZIONE VARCHAR(50) NOT NULL,
    CONTRAENTE VARCHAR(50) NOT NULL,
    COMMITTENTE VARCHAR(50) NOT NULL,
    ANNO INT NOT NULL,
    TIPO VARCHAR(50),
    DURATA INT,            -- ad es. durata in mesi
    IMPORTO DECIMAL(12,2), -- totale in euro
    CONSTRAINT FK_CONTRATTO_CONVENZIONE
        FOREIGN KEY (CONVENZIONE)
        REFERENCES CONVENZIONE (CONVENZIONE),
    CONSTRAINT FK_CONTRATTO_CONTRAENTE
        FOREIGN KEY (CONTRAENTE)
        REFERENCES PERSONA (PERSONA),
    CONSTRAINT FK_CONTRATTO_COMMITTENTE
        FOREIGN KEY (COMMITTENTE)
        REFERENCES PERSONA (PERSONA)
);
GO

---------------------------------------------------
-- 2) INSERIMENTO DATI DI TEST
---------------------------------------------------

---------------------------------------------------
-- Inserimento in CITTA
---------------------------------------------------
INSERT INTO CITTA (CITTÀ, STATO) VALUES
('Roma', 'Italia'),
('Milano', 'Italia'),
('Torino', 'Italia'),
('Napoli', 'Italia'),
('Londra', 'Regno Unito'),
('Manchester', 'Regno Unito'),
('New York', 'USA'),
('Los Angeles', 'USA'),
('Tokyo', 'Giappone'),
('Osaka', 'Giappone'),
('Berlino', 'Germania'),
('Amburgo', 'Germania'),
('Parigi', 'Francia'),
('Marsiglia', 'Francia'),
('Barcellona', 'Spagna'),
('Madrid', 'Spagna'),
('Zurigo', 'Svizzera'),
('Vienna', 'Austria'),
('Atene', 'Grecia'),
('Stoccolma', 'Svezia');
GO

---------------------------------------------------
-- Inserimento in PERSONA
---------------------------------------------------
INSERT INTO PERSONA (PERSONA, RESIDENZA, TITOLO_DI_STUDIO) VALUES
('Mario Rossi', 'Roma', 'Laurea'),
('Anna Bianchi', 'Milano', 'Diploma'),
('Luca Verdi', 'Torino', 'Laurea'),
('Sara Neri', 'Napoli', 'Master'),
('John Smith', 'New York', 'PhD'),
('Jane Doe', 'Los Angeles', 'Laurea'),
('Peter Brown', 'Londra', 'Diploma'),
('Lucy Green', 'Manchester', 'Laurea'),
('Hiro Tanaka', 'Tokyo', 'PhD'),
('Akira Sato', 'Osaka', 'Master'),
('Hans Müller', 'Berlino', 'Laurea'),
('Peter Schmidt', 'Amburgo', 'Diploma'),
('Marie Dubois', 'Parigi', 'Laurea'),
('Jeanne Moreau', 'Marsiglia', 'Diploma'),
('Pedro García', 'Barcellona', 'Master'),
('Luis Morales', 'Madrid', 'Laurea'),
('Urs Meier', 'Zurigo', 'PhD'),
('Heinz Berger', 'Vienna', 'Laurea'),
('Yorgos Papas', 'Atene', 'Master'),
('Greta Svensson', 'Stoccolma', 'Diploma');
GO

---------------------------------------------------
-- Inserimento in ISTITUZIONE (con DIRETTORE)
---------------------------------------------------
INSERT INTO ISTITUZIONE (ISTITUZIONE, SEDE_LEGALE, DIRETTORE) VALUES
('Università La Sapienza', 'Roma', 'Mario Rossi'),
('Politecnico Milano', 'Milano', 'Anna Bianchi'),
('Università di Tokyo', 'Tokyo', 'Hiro Tanaka'),
('Oxford University', 'Londra', 'Peter Brown'),
('Harvard', 'New York', 'John Smith'),
('Università Sorbona', 'Parigi', 'Marie Dubois'),
('Università di Barcellona', 'Barcellona', 'Pedro García'),
('Istituto di Tecnologia Vienna', 'Vienna', 'Heinz Berger'),
('Università di Stoccolma', 'Stoccolma', 'Greta Svensson'),
('Università di Napoli', 'Napoli', 'Sara Neri');
GO

---------------------------------------------------
-- Inserimento in CONVENZIONE
---------------------------------------------------
INSERT INTO CONVENZIONE (CONVENZIONE, GENERE, ISTITUZIONE) VALUES
('Conv001', 'Ricerca Scientifica', 'Università La Sapienza'),
('Conv002', 'Formazione', 'Politecnico Milano'),
('Conv003', 'Ricerca Scientifica', 'Università di Tokyo'),
('Conv004', 'Erasmus', 'Oxford University'),
('Conv005', 'Formazione', 'Harvard'),
('Conv006', 'Ricerca Scientifica', 'Università Sorbona'),
('Conv007', 'Scambio Culturale', 'Università di Barcellona'),
('Conv008', 'Formazione', 'Istituto di Tecnologia Vienna'),
('Conv009', 'Scambio Studenti', 'Università di Stoccolma'),
('Conv010', 'Erasmus', 'Università di Napoli');
GO

---------------------------------------------------
-- Inserimento in CONTRATTO (almeno 150 record)
---------------------------------------------------
-- Utilizziamo una tabella ausiliaria per generare 150 righe

DECLARE @numContratti INT = 150;
DECLARE @minAnno INT = 2010, @maxAnno INT = 2025;
DECLARE @minDurata INT = 1,   @maxDurata INT = 60;
DECLARE @minImporto INT = 1000, @maxImporto INT = 50000;

-- Creiamo una tabella di supporto (#Tally) per contare da 1 a @numContratti
WITH Tally (N) AS
(
    SELECT TOP (@numContratti) ROW_NUMBER() OVER (ORDER BY (SELECT NULL))
    FROM sys.all_objects
)
SELECT * INTO #Tally FROM Tally;
    
-- Inserimento record in CONTRATTO con dati casuali.
-- Le subquery in CROSS APPLY selezionano in modo casuale una convenzione e due persone dalla lista.
WITH 
CTE_Convenzioni AS (
    SELECT CONVENZIONE FROM CONVENZIONE
),
CTE_Persone AS (
    SELECT PERSONA FROM PERSONA
)
INSERT INTO CONTRATTO (CONVENZIONE, CONTRAENTE, COMMITTENTE, ANNO, TIPO, DURATA, IMPORTO)
SELECT 
    -- Selezione casuale di una convenzione
    (SELECT TOP 1 CONVENZIONE FROM CTE_Convenzioni ORDER BY ABS(CHECKSUM(NEWID()))),
    -- Selezione casuale per Contraente
    P1.PERSONA,
    -- Selezione casuale per Committente
    P2.PERSONA,
    -- Anno casuale
    @minAnno + (ABS(CHECKSUM(NEWID())) % (@maxAnno - @minAnno + 1)),
    -- Tipo casuale (4 opzioni)
    CASE (ABS(CHECKSUM(NEWID())) % 4)
        WHEN 0 THEN 'Temporary'
        WHEN 1 THEN 'Annual'
        WHEN 2 THEN 'Triennale'
        ELSE 'Quinquennale'
    END,
    -- Durata casuale
    @minDurata + (ABS(CHECKSUM(NEWID())) % (@maxDurata - @minDurata + 1)),
    -- Importo casuale
    CAST(@minImporto + (ABS(CHECKSUM(NEWID())) % (@maxImporto - @minImporto + 1)) AS DECIMAL(12,2))
FROM #Tally T
CROSS APPLY (
    SELECT TOP 1 PERSONA 
    FROM CTE_Persone 
    ORDER BY ABS(CHECKSUM(NEWID()))
) AS P1
CROSS APPLY (
    SELECT TOP 1 PERSONA 
    FROM CTE_Persone 
    ORDER BY ABS(CHECKSUM(NEWID()))
) AS P2
WHERE P1.PERSONA <> P2.PERSONA;
    
DROP TABLE #Tally;
GO

---------------------------------------------------
-- FINE DELLO SCRIPT
---------------------------------------------------
