CREATE TABLE clases (
  cod NUMBER(2),
  nombre VARCHAR2(20),
  ingresos NUMBER(10,2),
  num_pob NUMBER(3),
  PRIMARY KEY (cod)
);

CREATE TABLE personajes (
  id VARCHAR2(3), 
  nombre VARCHAR(36), 
  fechanac DATE,
  cp VARCHAR2(5),
  sexo VARCHAR2(1),
  patrimonio NUMBER(10,2),
  clase NUMBER(2), 
  PRIMARY KEY (id),
  FOREIGN KEY (clase) REFERENCES clases (cod) ON DELETE SET NULL
);

INSERT INTO clases
  VALUES (1,'Nobleza',0, 0);

INSERT INTO clases
  VALUES (2,'Clero',0, 0);

INSERT INTO clases
  VALUES (3,'Artesanos',0, 0);

INSERT INTO clases
  VALUES (4,'Campesinos',0, 0);



INSERT INTO personajes
  VALUES ('123','Calixto Pérez','15/11/1757','06300','H',150,4);

INSERT INTO personajes
  VALUES ('777','Gervasio Romualdo','12/12/1721','06002','H',230,4);

INSERT INTO personajes
  VALUES ('222','Prudencio González','01/02/1720','06300','H',220,4);

INSERT INTO personajes
  VALUES ('333','Macaria Gil','10/04/1731','06400','M',195,4);

INSERT INTO personajes
  VALUES ('666','Honorio Marín','12/12/1742','10005','H',370,4);

INSERT INTO personajes
  VALUES ('555','Venancio Fernández','15/11/1738','10600','H',4600,3);

INSERT INTO personajes
  VALUES ('696','Balbina Sánchez','12/04/1734','06400','M',5000,3);

INSERT INTO personajes
  VALUES ('888','Faustino Martínez','30/05/1731','06002','H',7000,3);

INSERT INTO personajes
  VALUES ('999','Facundo Fernández','12/03/1739','10800','H',6300,3);

INSERT INTO personajes
  VALUES ('444','Pandulfa Ruiz','01/02/1750','06800','M',2500,3);

INSERT INTO personajes
  VALUES ('987','Eduviges Pozo','10/05/1734','10005','M',40000,2);
  
INSERT INTO personajes
  VALUES ('234','Abundio Hernández','01/07/1749','06800','H',25000,2);

INSERT INTO personajes
  VALUES ('345','Salustiana Moreno','07/04/1733','10300','M',40000,2);

INSERT INTO personajes
  VALUES ('567','Camelia Cortés','12/05/1736','10600','M',48000,2);

INSERT INTO personajes
  VALUES ('789','Sagrario Méndez','22/06/1759','10800','M',18000,2);

INSERT INTO personajes
  VALUES ('901','Amable Montero','07/04/1760','10300','H',140000,1);

INSERT INTO personajes
  VALUES ('012','Martiniano Zarzal','23/11/1736','10005','H',360000,1);

INSERT INTO personajes
  VALUES ('876','Mederica Campos','19/03/1734','06800','M',500000,1);

INSERT INTO personajes
  VALUES ('321','Filiberto Torres','08/08/1748','06002','H',250000,1);

INSERT INTO personajes
  VALUES ('221','Obdulia Candil','08/08/1737','10005','M',502000,1);