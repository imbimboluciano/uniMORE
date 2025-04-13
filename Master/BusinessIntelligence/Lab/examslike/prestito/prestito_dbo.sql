/****** Object:  Table [dbo].[BIBLIOTECA]    Script Date: 08/12/2023 09:14:47 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[BIBLIOTECA](
	[BIBLIOTECA] [nchar](10) NOT NULL,
	[CITTA] [nchar](10) NULL,
 CONSTRAINT [PK_BIBLIOTECA] PRIMARY KEY CLUSTERED 
(
	[BIBLIOTECA] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[BOX_RESI]    Script Date: 08/12/2023 09:14:47 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[BOX_RESI](
	[BOX_RESI] [nchar](10) NOT NULL,
	[BIBLIOTECA] [nchar](10) NULL,
	[CITTA] [nchar](10) NULL,
 CONSTRAINT [PK_SPORTELLO_BOX] PRIMARY KEY CLUSTERED 
(
	[BOX_RESI] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[CITTA]    Script Date: 08/12/2023 09:14:47 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CITTA](
	[CITTA] [nchar](10) NOT NULL,
	[POPOLAZIONE] [nchar](10) NULL,
	[REGIONE] [nchar](10) NULL,
 CONSTRAINT [PK_CITTA] PRIMARY KEY CLUSTERED 
(
	[CITTA] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[PRESTITO]    Script Date: 08/12/2023 09:14:47 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PRESTITO](
	[COD] [nchar](10) NOT NULL,
	[BIBLIOTECA] [nchar](10) NOT NULL,
	[TESSERA] [nchar](10) NULL,
	[LIBRO] [nchar](10) NULL,
	[PREZZO] [numeric](18, 0) NULL,
	[DATA] [date] NULL,
 CONSTRAINT [PK_PRESTITO] PRIMARY KEY CLUSTERED 
(
	[COD] ASC,
	[BIBLIOTECA] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[RESTITUZIONE]    Script Date: 08/12/2023 09:14:47 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[RESTITUZIONE](
	[COD] [nchar](10) NOT NULL,
	[BIBLIOTECA] [nchar](10) NOT NULL,
	[BOX_RESI] [nchar](10) NULL,
	[DATARESTITUZIONE] [date] NULL,
 CONSTRAINT [PK_RESTITUZIONE] PRIMARY KEY CLUSTERED 
(
	[COD] ASC,
	[BIBLIOTECA] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TESSERA]    Script Date: 08/12/2023 09:14:47 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TESSERA](
	[TESSERA] [nchar](10) NOT NULL,
	[UTENTE] [nchar](10) NULL,
	[TIPO] [nchar](10) NULL,
 CONSTRAINT [PK_TESSERA] PRIMARY KEY CLUSTERED 
(
	[TESSERA] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[UTENTE]    Script Date: 08/12/2023 09:14:47 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[UTENTE](
	[UTENTE] [nchar](10) NOT NULL,
	[BIBLIOTECA] [nchar](10) NULL,
	[CITTA] [nchar](10) NULL,
 CONSTRAINT [PK_CLIENTE] PRIMARY KEY CLUSTERED 
(
	[UTENTE] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[BIBLIOTECA] ([BIBLIOTECA], [CITTA]) VALUES (N'b1        ', N'c1        ')
GO
INSERT [dbo].[BIBLIOTECA] ([BIBLIOTECA], [CITTA]) VALUES (N'b10       ', N'c3        ')
GO
INSERT [dbo].[BIBLIOTECA] ([BIBLIOTECA], [CITTA]) VALUES (N'b2        ', N'c2        ')
GO
INSERT [dbo].[BIBLIOTECA] ([BIBLIOTECA], [CITTA]) VALUES (N'b3        ', N'c3        ')
GO
INSERT [dbo].[BIBLIOTECA] ([BIBLIOTECA], [CITTA]) VALUES (N'b4        ', N'c4        ')
GO
INSERT [dbo].[BIBLIOTECA] ([BIBLIOTECA], [CITTA]) VALUES (N'b5        ', N'c5        ')
GO
INSERT [dbo].[BIBLIOTECA] ([BIBLIOTECA], [CITTA]) VALUES (N'b6        ', N'c5        ')
GO
INSERT [dbo].[BIBLIOTECA] ([BIBLIOTECA], [CITTA]) VALUES (N'b7        ', N'c5        ')
GO
INSERT [dbo].[BIBLIOTECA] ([BIBLIOTECA], [CITTA]) VALUES (N'b8        ', N'c1        ')
GO
INSERT [dbo].[BIBLIOTECA] ([BIBLIOTECA], [CITTA]) VALUES (N'b9        ', N'c3        ')
GO
INSERT [dbo].[BIBLIOTECA] ([BIBLIOTECA], [CITTA]) VALUES (N'NO        ', N'NO        ')
GO
INSERT [dbo].[BOX_RESI] ([BOX_RESI], [BIBLIOTECA], [CITTA]) VALUES (N'br1       ', N'b1        ', N'c1        ')
GO
INSERT [dbo].[BOX_RESI] ([BOX_RESI], [BIBLIOTECA], [CITTA]) VALUES (N'br10      ', N'b9        ', N'c2        ')
GO
INSERT [dbo].[BOX_RESI] ([BOX_RESI], [BIBLIOTECA], [CITTA]) VALUES (N'br11      ', N'b10       ', N'c3        ')
GO
INSERT [dbo].[BOX_RESI] ([BOX_RESI], [BIBLIOTECA], [CITTA]) VALUES (N'br2       ', N'b1        ', N'c2        ')
GO
INSERT [dbo].[BOX_RESI] ([BOX_RESI], [BIBLIOTECA], [CITTA]) VALUES (N'br3       ', N'b2        ', N'c2        ')
GO
INSERT [dbo].[BOX_RESI] ([BOX_RESI], [BIBLIOTECA], [CITTA]) VALUES (N'br4       ', N'b3        ', N'c3        ')
GO
INSERT [dbo].[BOX_RESI] ([BOX_RESI], [BIBLIOTECA], [CITTA]) VALUES (N'br5       ', N'b4        ', N'c4        ')
GO
INSERT [dbo].[BOX_RESI] ([BOX_RESI], [BIBLIOTECA], [CITTA]) VALUES (N'br6       ', N'b5        ', N'c4        ')
GO
INSERT [dbo].[BOX_RESI] ([BOX_RESI], [BIBLIOTECA], [CITTA]) VALUES (N'br7       ', N'b6        ', N'c5        ')
GO
INSERT [dbo].[BOX_RESI] ([BOX_RESI], [BIBLIOTECA], [CITTA]) VALUES (N'br8       ', N'b7        ', N'c5        ')
GO
INSERT [dbo].[BOX_RESI] ([BOX_RESI], [BIBLIOTECA], [CITTA]) VALUES (N'br9       ', N'b8        ', N'c1        ')
GO
INSERT [dbo].[BOX_RESI] ([BOX_RESI], [BIBLIOTECA], [CITTA]) VALUES (N'NO        ', N'NO        ', N'NO        ')
GO
INSERT [dbo].[CITTA] ([CITTA], [POPOLAZIONE], [REGIONE]) VALUES (N'c1        ', N'100       ', N'r1        ')
GO
INSERT [dbo].[CITTA] ([CITTA], [POPOLAZIONE], [REGIONE]) VALUES (N'c2        ', N'200       ', N'r3        ')
GO
INSERT [dbo].[CITTA] ([CITTA], [POPOLAZIONE], [REGIONE]) VALUES (N'c3        ', N'100       ', N'r3        ')
GO
INSERT [dbo].[CITTA] ([CITTA], [POPOLAZIONE], [REGIONE]) VALUES (N'c4        ', N'250       ', N'r2        ')
GO
INSERT [dbo].[CITTA] ([CITTA], [POPOLAZIONE], [REGIONE]) VALUES (N'c5        ', N'300       ', N'r1        ')
GO
INSERT [dbo].[CITTA] ([CITTA], [POPOLAZIONE], [REGIONE]) VALUES (N'NO        ', N'NO        ', N'NO        ')
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'1         ', N'b1        ', N't18       ', N'l18       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-01' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'1         ', N'b10       ', N't9        ', N'l24       ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-01' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'1         ', N'b2        ', N't6        ', N'l13       ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-01' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'1         ', N'b3        ', N't20       ', N'l6        ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-01' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'1         ', N'b4        ', N't23       ', N'l25       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-01' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'1         ', N'b5        ', N't24       ', N'l3        ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-01' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'1         ', N'b6        ', N't11       ', N'l4        ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-02' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'1         ', N'b7        ', N't17       ', N'l19       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-01' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'1         ', N'b8        ', N't1        ', N'l12       ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-01' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'1         ', N'b9        ', N't12       ', N'l21       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-01' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'10        ', N'b1        ', N't9        ', N'l18       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'10        ', N'b10       ', N't9        ', N'l24       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'10        ', N'b2        ', N't15       ', N'l13       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'10        ', N'b3        ', N't20       ', N'l6        ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'10        ', N'b4        ', N't14       ', N'l25       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-15' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'10        ', N'b5        ', N't10       ', N'l30       ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'10        ', N'b6        ', N't20       ', N'l4        ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'10        ', N'b7        ', N't8        ', N'l14       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'10        ', N'b8        ', N't19       ', N'l26       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'10        ', N'b9        ', N't3        ', N'l21       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'11        ', N'b1        ', N't13       ', N'l18       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-16' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'11        ', N'b10       ', N't18       ', N'l22       ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'11        ', N'b2        ', N't2        ', N'l13       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-15' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'11        ', N'b3        ', N't25       ', N'l6        ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'11        ', N'b4        ', N't19       ', N'l25       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-16' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'11        ', N'b5        ', N't2        ', N'l28       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'11        ', N'b6        ', N't25       ', N'l4        ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-15' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'11        ', N'b7        ', N't17       ', N'l29       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-11' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'11        ', N'b8        ', N't14       ', N'l12       ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'11        ', N'b9        ', N't12       ', N'l7        ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-15' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'111       ', N'b3        ', N't5        ', N'l18       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-03' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'111       ', N'b4        ', N't2        ', N'l25       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-04' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'111       ', N'b6        ', N't23       ', N'l4        ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'111       ', N'b8        ', N't24       ', N'l18       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-02' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'12        ', N'b1        ', N't18       ', N'l18       ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'12        ', N'b10       ', N't13       ', N'l24       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-11' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'12        ', N'b2        ', N't24       ', N'l13       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-16' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'12        ', N'b3        ', N't7        ', N'l6        ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-11' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'12        ', N'b4        ', N't1        ', N'l27       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-16' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'12        ', N'b5        ', N't24       ', N'l28       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-11' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'12        ', N'b6        ', N't7        ', N'l4        ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-16' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'12        ', N'b7        ', N't8        ', N'l19       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'12        ', N'b8        ', N't1        ', N'l16       ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-11' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'12        ', N'b9        ', N't8        ', N'l21       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-15' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'13        ', N'b1        ', N't4        ', N'l17       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'13        ', N'b10       ', N't9        ', N'l8        ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-11' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'13        ', N'b2        ', N't6        ', N'l13       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'13        ', N'b3        ', N't16       ', N'l10       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'13        ', N'b4        ', N't23       ', N'l25       ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'13        ', N'b5        ', N't6        ', N'l28       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'13        ', N'b6        ', N't11       ', N'l4        ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-18' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'13        ', N'b7        ', N't12       ', N'l14       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'13        ', N'b8        ', N't5        ', N'l26       ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-11' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'13        ', N'b9        ', N't12       ', N'l21       ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'14        ', N'b1        ', N't22       ', N'l18       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-18' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'14        ', N'b10       ', N't18       ', N'l24       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'14        ', N'b2        ', N't24       ', N'l5        ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-18' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'14        ', N'b3        ', N't25       ', N'l2        ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'14        ', N'b4        ', N't5        ', N'l25       ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-18' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'14        ', N'b5        ', N't15       ', N'l3        ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-15' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'14        ', N'b6        ', N't16       ', N'l4        ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'14        ', N'b7        ', N't17       ', N'l14       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-15' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'14        ', N'b8        ', N't19       ', N'l12       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-11' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'14        ', N'b9        ', N't17       ', N'l21       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-18' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'15        ', N'b1        ', N't4        ', N'l18       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'15        ', N'b10       ', N't22       ', N'l24       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-15' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'15        ', N'b2        ', N't10       ', N'l13       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'15        ', N'b3        ', N't11       ', N'l6        ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-15' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'15        ', N'b4        ', N't19       ', N'l20       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'15        ', N'b5        ', N't10       ', N'l28       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-16' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'15        ', N'b6        ', N't20       ', N'l4        ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'15        ', N'b7        ', N't21       ', N'l14       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-16' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'15        ', N'b8        ', N't23       ', N'l12       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'15        ', N'b9        ', N't21       ', N'l21       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'16        ', N'b1        ', N't9        ', N'l18       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'16        ', N'b10       ', N't4        ', N'l24       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-16' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'16        ', N'b2        ', N't15       ', N'l13       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'16        ', N'b3        ', N't7        ', N'l2        ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-15' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'16        ', N'b4        ', N't1        ', N'l25       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'16        ', N'b5        ', N't2        ', N'l3        ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-16' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'16        ', N'b6        ', N't25       ', N'l4        ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'16        ', N'b7        ', N't17       ', N'l19       ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'16        ', N'b8        ', N't5        ', N'l12       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-15' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'16        ', N'b9        ', N't3        ', N'l21       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'17        ', N'b1        ', N't13       ', N'l18       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-24' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'17        ', N'b10       ', N't13       ', N'l22       ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'17        ', N'b2        ', N't2        ', N'l13       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'17        ', N'b3        ', N't16       ', N'l6        ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-16' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'17        ', N'b4        ', N't14       ', N'l25       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'17        ', N'b5        ', N't6        ', N'l30       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-16' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'17        ', N'b6        ', N't16       ', N'l23       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'17        ', N'b7        ', N't3        ', N'l14       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'17        ', N'b8        ', N't14       ', N'l26       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-16' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'17        ', N'b9        ', N't8        ', N'l21       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'18        ', N'b1        ', N't18       ', N'l18       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'18        ', N'b10       ', N't9        ', N'l24       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'18        ', N'b2        ', N't24       ', N'l13       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-24' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'18        ', N'b3        ', N't20       ', N'l6        ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'18        ', N'b4        ', N't19       ', N'l25       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-24' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'18        ', N'b5        ', N't15       ', N'l28       ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'18        ', N'b6        ', N't7        ', N'l4        ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-24' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'18        ', N'b7        ', N't12       ', N'l29       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-18' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'18        ', N'b8        ', N't1        ', N'l12       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'18        ', N'b9        ', N't12       ', N'l21       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'19        ', N'b1        ', N't22       ', N'l18       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-26' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'19        ', N'b10       ', N't4        ', N'l8        ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-18' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'19        ', N'b2        ', N't10       ', N'l15       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'19        ', N'b3        ', N't25       ', N'l6        ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-18' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'19        ', N'b4        ', N't23       ', N'l25       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'19        ', N'b5        ', N't2        ', N'l28       ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-18' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'19        ', N'b6        ', N't11       ', N'l4        ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-26' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'19        ', N'b7        ', N't8        ', N'l14       ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-18' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'19        ', N'b8        ', N't5        ', N'l16       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'19        ', N'b9        ', N't8        ', N'l11       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'2         ', N'b1        ', N't22       ', N'l18       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-02' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'2         ', N'b10       ', N't4        ', N'l8        ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-02' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'2         ', N'b2        ', N't2        ', N'l5        ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-01' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'2         ', N'b3        ', N't7        ', N'l10       ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-01' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'2         ', N'b4        ', N't5        ', N'l25       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-02' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'2         ', N'b5        ', N't15       ', N'l28       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-01' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'2         ', N'b6        ', N't16       ', N'l4        ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-03' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'2         ', N'b7        ', N't3        ', N'l14       ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-01' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'2         ', N'b8        ', N't14       ', N'l12       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-02' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'2         ', N'b9        ', N't17       ', N'l21       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-02' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'20        ', N'b10       ', N't13       ', N'l24       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'20        ', N'b2        ', N't6        ', N'l13       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'20        ', N'b3        ', N't11       ', N'l10       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'20        ', N'b4        ', N't5        ', N'l25       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-26' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'20        ', N'b5        ', N't24       ', N'l28       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'20        ', N'b7        ', N't3        ', N'l19       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'20        ', N'b8        ', N't14       ', N'l12       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-18' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'20        ', N'b9        ', N't17       ', N'l21       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-26' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'21        ', N'b10       ', N't9        ', N'l8        ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'21        ', N'b3        ', N't7        ', N'l6        ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'21        ', N'b5        ', N't10       ', N'l3        ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'21        ', N'b7        ', N't12       ', N'l14       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'21        ', N'b8        ', N't19       ', N'l12       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'22        ', N'b10       ', N't18       ', N'l24       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'22        ', N'b3        ', N't25       ', N'l2        ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'22        ', N'b5        ', N't6        ', N'l28       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'22        ', N'b7        ', N't17       ', N'l14       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'22        ', N'b8        ', N't23       ', N'l12       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'222       ', N'b6        ', N't24       ', N'l4        ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'23        ', N'b10       ', N't9        ', N'l22       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'23        ', N'b3        ', N't11       ', N'l6        ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'23        ', N'b5        ', N't24       ', N'l30       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'23        ', N'b7        ', N't3        ', N'l29       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'23        ', N'b8        ', N't1        ', N'l26       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'24        ', N'b10       ', N't22       ', N'l24       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'24        ', N'b3        ', N't16       ', N'l6        ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-24' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'24        ', N'b5        ', N't10       ', N'l28       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-24' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'24        ', N'b7        ', N't21       ', N'l14       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-24' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'24        ', N'b8        ', N't5        ', N'l12       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'25        ', N'b10       ', N't4        ', N'l24       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-24' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'25        ', N'b3        ', N't20       ', N'l6        ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'25        ', N'b5        ', N't15       ', N'l28       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'25        ', N'b7        ', N't8        ', N'l29       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-24' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'25        ', N'b8        ', N't23       ', N'l16       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-24' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'26        ', N'b10       ', N't22       ', N'l8        ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'26        ', N'b3        ', N't7        ', N'l10       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'26        ', N'b5        ', N't6        ', N'l3        ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-26' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'26        ', N'b7        ', N't3        ', N'l14       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'26        ', N'b8        ', N't1        ', N'l12       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'27        ', N'b10       ', N't9        ', N'l24       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'27        ', N'b3        ', N't25       ', N'l6        ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-26' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'27        ', N'b5        ', N't2        ', N'l28       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-26' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'27        ', N'b7        ', N't21       ', N'l19       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-26' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'27        ', N'b8        ', N't14       ', N'l12       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-26' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'28        ', N'b10       ', N't18       ', N'l22       ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-26' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'28        ', N'b7        ', N't8        ', N'l14       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-26' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'3         ', N'b1        ', N't4        ', N'l18       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-03' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'3         ', N'b10       ', N't13       ', N'l24       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-03' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'3         ', N'b2        ', N't10       ', N'l13       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-03' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'3         ', N'b3        ', N't16       ', N'l2        ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-02' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'3         ', N'b4        ', N't14       ', N'l20       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-03' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'3         ', N'b5        ', N't2        ', N'l28       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-02' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'3         ', N'b6        ', N't11       ', N'l23       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-04' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'3         ', N'b7        ', N't8        ', N'l14       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-02' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'3         ', N'b8        ', N't23       ', N'l26       ', CAST(9 AS Numeric(18, 0)), CAST(N'2018-10-02' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'3         ', N'b9        ', N't21       ', N'l21       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-03' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'4         ', N'b1        ', N't9        ', N'l18       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-04' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'4         ', N'b10       ', N't22       ', N'l22       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-03' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'4         ', N'b2        ', N't15       ', N'l13       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-04' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'4         ', N'b3        ', N't25       ', N'l6        ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-02' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'4         ', N'b4        ', N't1        ', N'l25       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-04' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'4         ', N'b5        ', N't15       ', N'l30       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-03' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'4         ', N'b6        ', N't20       ', N'l4        ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-04' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'4         ', N'b7        ', N't12       ', N'l14       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-04' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'4         ', N'b8        ', N't19       ', N'l12       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-03' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'4         ', N'b9        ', N't3        ', N'l21       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-04' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'5         ', N'b1        ', N't13       ', N'l18       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-08' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'5         ', N'b10       ', N't18       ', N'l24       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-04' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'5         ', N'b2        ', N't6        ', N'l15       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'5         ', N'b3        ', N't7        ', N'l6        ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-03' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'5         ', N'b4        ', N't14       ', N'l25       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'5         ', N'b5        ', N't24       ', N'l28       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-03' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'5         ', N'b6        ', N't25       ', N'l4        ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'5         ', N'b7        ', N't21       ', N'l29       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-04' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'5         ', N'b8        ', N't14       ', N'l16       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-04' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'5         ', N'b9        ', N't8        ', N'l21       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'6         ', N'b1        ', N't18       ', N'l18       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'6         ', N'b10       ', N't13       ', N'l8        ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'6         ', N'b2        ', N't2        ', N'l13       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'6         ', N'b3        ', N't20       ', N'l10       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'6         ', N'b4        ', N't19       ', N'l25       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-08' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'6         ', N'b5        ', N't6        ', N'l28       ', CAST(10 AS Numeric(18, 0)), CAST(N'2018-10-04' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'6         ', N'b6        ', N't7        ', N'l4        ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-08' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'6         ', N'b7        ', N't17       ', N'l14       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'6         ', N'b8        ', N't23       ', N'l12       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-04' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'6         ', N'b9        ', N't3        ', N'l11       ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-08' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'7         ', N'b1        ', N't22       ', N'l18       ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'7         ', N'b10       ', N't22       ', N'l24       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'7         ', N'b2        ', N't24       ', N'l13       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-08' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'7         ', N'b3        ', N't11       ', N'l6        ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'7         ', N'b4        ', N't23       ', N'l25       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'7         ', N'b5        ', N't2        ', N'l3        ', CAST(3 AS Numeric(18, 0)), CAST(N'2018-10-08' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'7         ', N'b6        ', N't20       ', N'l9        ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'7         ', N'b7        ', N't12       ', N'l19       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-08' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'7         ', N'b8        ', N't19       ', N'l16       ', CAST(2 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'7         ', N'b9        ', N't12       ', N'l21       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'8         ', N'b1        ', N't18       ', N'l1        ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-11' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'8         ', N'b10       ', N't4        ', N'l24       ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-08' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'8         ', N'b2        ', N't6        ', N'l13       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'8         ', N'b3        ', N't16       ', N'l6        ', CAST(4 AS Numeric(18, 0)), CAST(N'2018-10-08' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'8         ', N'b4        ', N't5        ', N'l25       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'8         ', N'b5        ', N't10       ', N'l28       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-08' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'8         ', N'b6        ', N't11       ', N'l4        ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'8         ', N'b7        ', N't21       ', N'l14       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-08' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'8         ', N'b8        ', N't5        ', N'l12       ', CAST(1 AS Numeric(18, 0)), CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'8         ', N'b9        ', N't17       ', N'l21       ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'9         ', N'b1        ', N't4        ', N'l18       ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-11' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'9         ', N'b10       ', N't13       ', N'l22       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'9         ', N'b2        ', N't10       ', N'l13       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-11' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'9         ', N'b3        ', N't11       ', N'l2        ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'9         ', N'b4        ', N't1        ', N'l25       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'9         ', N'b5        ', N't15       ', N'l28       ', CAST(6 AS Numeric(18, 0)), CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'9         ', N'b6        ', N't16       ', N'l4        ', CAST(7 AS Numeric(18, 0)), CAST(N'2018-10-11' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'9         ', N'b7        ', N't3        ', N'l14       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'9         ', N'b8        ', N't1        ', N'l12       ', CAST(5 AS Numeric(18, 0)), CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[PRESTITO] ([COD], [BIBLIOTECA], [TESSERA], [LIBRO], [PREZZO], [DATA]) VALUES (N'9         ', N'b9        ', N't21       ', N'l21       ', CAST(8 AS Numeric(18, 0)), CAST(N'2018-10-11' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'1         ', N'b1        ', N'br7       ', CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'1         ', N'b4        ', N'br7       ', CAST(N'2018-10-09' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'1         ', N'b9        ', N'br5       ', CAST(N'2018-10-07' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'10        ', N'b1        ', N'br7       ', CAST(N'2018-10-20' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'10        ', N'b10       ', N'br8       ', CAST(N'2018-10-18' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'10        ', N'b3        ', N'br7       ', CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'10        ', N'b4        ', N'br3       ', CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'10        ', N'b6        ', N'br8       ', CAST(N'2018-10-21' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'11        ', N'b1        ', N'br7       ', CAST(N'2018-10-24' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'11        ', N'b6        ', N'br3       ', CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'12        ', N'b1        ', N'br5       ', CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'12        ', N'b2        ', N'br10      ', CAST(N'2018-10-27' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'12        ', N'b3        ', N'br10      ', CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'12        ', N'b8        ', N'br3       ', CAST(N'2018-10-15' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'12        ', N'b9        ', N'br3       ', CAST(N'2018-10-19' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'13        ', N'b2        ', N'br7       ', CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'13        ', N'b4        ', N'br5       ', CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'14        ', N'b4        ', N'br1       ', CAST(N'2018-10-20' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'14        ', N'b9        ', N'br1       ', CAST(N'2018-10-20' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'15        ', N'b10       ', N'br1       ', CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'15        ', N'b2        ', N'br7       ', CAST(N'2018-10-27' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'15        ', N'b4        ', N'br10      ', CAST(N'2018-11-02' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'17        ', N'b10       ', N'br10      ', CAST(N'2018-10-28' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'17        ', N'b2        ', N'br3       ', CAST(N'2018-10-27' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'17        ', N'b3        ', N'br7       ', CAST(N'2018-10-24' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'17        ', N'b5        ', N'br5       ', CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'18        ', N'b5        ', N'br7       ', CAST(N'2018-10-25' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'2         ', N'b10       ', N'br7       ', CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'2         ', N'b5        ', N'br8       ', CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'2         ', N'b8        ', N'br9       ', CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'20        ', N'b3        ', N'br1       ', CAST(N'2018-10-21' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'20        ', N'b4        ', N'br6       ', CAST(N'2018-11-02' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'20        ', N'b7        ', N'br8       ', CAST(N'2018-10-28' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'20        ', N'b9        ', N'br6       ', CAST(N'2018-11-02' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'21        ', N'b10       ', N'br11      ', CAST(N'2018-10-22' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'21        ', N'b7        ', N'br2       ', CAST(N'2018-10-23' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'22        ', N'b3        ', N'br9       ', CAST(N'2018-11-01' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'22        ', N'b7        ', N'br7       ', CAST(N'2018-10-31' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'23        ', N'b7        ', N'br7       ', CAST(N'2018-10-31' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'24        ', N'b5        ', N'br11      ', CAST(N'2018-10-27' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'24        ', N'b8        ', N'br7       ', CAST(N'2018-10-31' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'25        ', N'b7        ', N'br7       ', CAST(N'2018-11-01' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'26        ', N'b10       ', N'br7       ', CAST(N'2018-11-02' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'26        ', N'b8        ', N'br7       ', CAST(N'2018-11-02' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'27        ', N'b5        ', N'br9       ', CAST(N'2018-11-05' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'27        ', N'b7        ', N'br7       ', CAST(N'2018-11-03' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'3         ', N'b7        ', N'br9       ', CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'4         ', N'b10       ', N'br6       ', CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'4         ', N'b3        ', N'br7       ', CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'4         ', N'b4        ', N'br8       ', CAST(N'2018-10-13' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'4         ', N'b8        ', N'br4       ', CAST(N'2018-10-08' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'5         ', N'b10       ', N'br2       ', CAST(N'2018-10-05' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'5         ', N'b4        ', N'br7       ', CAST(N'2018-10-13' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'6         ', N'b2        ', N'br7       ', CAST(N'2018-10-13' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'6         ', N'b3        ', N'br11      ', CAST(N'2018-10-08' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'6         ', N'b6        ', N'br4       ', CAST(N'2018-10-13' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'7         ', N'b2        ', N'br4       ', CAST(N'2018-10-13' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'7         ', N'b4        ', N'br2       ', CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'8         ', N'b2        ', N'br2       ', CAST(N'2018-10-10' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'8         ', N'b6        ', N'br6       ', CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'9         ', N'b10       ', N'br4       ', CAST(N'2018-10-14' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'9         ', N'b3        ', N'br7       ', CAST(N'2018-10-17' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'9         ', N'b6        ', N'br11      ', CAST(N'2018-10-14' AS Date))
GO
INSERT [dbo].[RESTITUZIONE] ([COD], [BIBLIOTECA], [BOX_RESI], [DATARESTITUZIONE]) VALUES (N'9         ', N'b7        ', N'br11      ', CAST(N'2018-10-12' AS Date))
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N'NO        ', N'NO        ', N'NO        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't1        ', N'cl1       ', N'T1        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't10       ', N'cl7       ', N'T3        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't11       ', N'cl8       ', N'T3        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't12       ', N'cl9       ', N'T1        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't13       ', N'cl10      ', N'T1        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't14       ', N'cl11      ', N'T1        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't15       ', N'cl12      ', N'T2        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't16       ', N'cl13      ', N'T3        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't17       ', N'cl14      ', N'T3        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't18       ', N'cl15      ', N'T3        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't19       ', N'cl16      ', N'T2        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't2        ', N'cl1       ', N'T2        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't20       ', N'cl17      ', N'T1        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't21       ', N'cl18      ', N'T1        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't22       ', N'cl19      ', N'T1        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't23       ', N'cl20      ', N'T1        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't24       ', N'cl20      ', N'T3        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't25       ', N'cl20      ', N'T1        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't3        ', N'cl1       ', N'T1        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't4        ', N'cl2       ', N'T1        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't5        ', N'cl2       ', N'T3        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't6        ', N'cl3       ', N'T2        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't7        ', N'cl4       ', N'T2        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't8        ', N'cl5       ', N'T3        ')
GO
INSERT [dbo].[TESSERA] ([TESSERA], [UTENTE], [TIPO]) VALUES (N't9        ', N'cl6       ', N'T1        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl1       ', N'b1        ', N'c1        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl10      ', N'b7        ', N'c3        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl11      ', N'b7        ', N'c2        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl12      ', N'b7        ', N'c1        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl13      ', N'b5        ', N'c1        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl14      ', N'b6        ', N'c1        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl15      ', N'b2        ', N'c3        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl16      ', N'b3        ', N'c3        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl17      ', N'b4        ', N'c5        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl18      ', N'b5        ', N'c5        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl19      ', N'b5        ', N'c5        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl2       ', N'b1        ', N'c1        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl20      ', N'b10       ', N'c1        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl3       ', N'b1        ', N'c3        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl4       ', N'b3        ', N'c3        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl5       ', N'b3        ', N'c3        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl6       ', N'b5        ', N'c4        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl7       ', N'b5        ', N'c5        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl8       ', N'b10       ', N'c5        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'cl9       ', N'b9        ', N'c3        ')
GO
INSERT [dbo].[UTENTE] ([UTENTE], [BIBLIOTECA], [CITTA]) VALUES (N'NO        ', N'NO        ', N'NO        ')
GO
ALTER TABLE [dbo].[BIBLIOTECA]  WITH CHECK ADD  CONSTRAINT [FK_BIBLIOTECA_CITTA] FOREIGN KEY([CITTA])
REFERENCES [dbo].[CITTA] ([CITTA])
GO
ALTER TABLE [dbo].[BIBLIOTECA] CHECK CONSTRAINT [FK_BIBLIOTECA_CITTA]
GO
ALTER TABLE [dbo].[BOX_RESI]  WITH CHECK ADD  CONSTRAINT [FK_BOX-RESI_BIBLIOTECA] FOREIGN KEY([BIBLIOTECA])
REFERENCES [dbo].[BIBLIOTECA] ([BIBLIOTECA])
GO
ALTER TABLE [dbo].[BOX_RESI] CHECK CONSTRAINT [FK_BOX-RESI_BIBLIOTECA]
GO
ALTER TABLE [dbo].[BOX_RESI]  WITH CHECK ADD  CONSTRAINT [FK_BOX-RESI_CITTA] FOREIGN KEY([CITTA])
REFERENCES [dbo].[CITTA] ([CITTA])
GO
ALTER TABLE [dbo].[BOX_RESI] CHECK CONSTRAINT [FK_BOX-RESI_CITTA]
GO
ALTER TABLE [dbo].[PRESTITO]  WITH CHECK ADD  CONSTRAINT [FK_PRESTITO_BIBLIOTECA] FOREIGN KEY([BIBLIOTECA])
REFERENCES [dbo].[BIBLIOTECA] ([BIBLIOTECA])
GO
ALTER TABLE [dbo].[PRESTITO] CHECK CONSTRAINT [FK_PRESTITO_BIBLIOTECA]
GO
ALTER TABLE [dbo].[PRESTITO]  WITH CHECK ADD  CONSTRAINT [FK_PRESTITO_TESSERA] FOREIGN KEY([TESSERA])
REFERENCES [dbo].[TESSERA] ([TESSERA])
GO
ALTER TABLE [dbo].[PRESTITO] CHECK CONSTRAINT [FK_PRESTITO_TESSERA]
GO
ALTER TABLE [dbo].[RESTITUZIONE]  WITH CHECK ADD  CONSTRAINT [FK_RESTITUZIONE_BOX-RESI] FOREIGN KEY([BOX_RESI])
REFERENCES [dbo].[BOX_RESI] ([BOX_RESI])
GO
ALTER TABLE [dbo].[RESTITUZIONE] CHECK CONSTRAINT [FK_RESTITUZIONE_BOX-RESI]
GO
ALTER TABLE [dbo].[RESTITUZIONE]  WITH CHECK ADD  CONSTRAINT [FK_RESTITUZIONE_PRESTITO] FOREIGN KEY([COD], [BIBLIOTECA])
REFERENCES [dbo].[PRESTITO] ([COD], [BIBLIOTECA])
GO
ALTER TABLE [dbo].[RESTITUZIONE] CHECK CONSTRAINT [FK_RESTITUZIONE_PRESTITO]
GO
ALTER TABLE [dbo].[TESSERA]  WITH CHECK ADD  CONSTRAINT [FK_TESSERA_CLIENTE] FOREIGN KEY([UTENTE])
REFERENCES [dbo].[UTENTE] ([UTENTE])
GO
ALTER TABLE [dbo].[TESSERA] CHECK CONSTRAINT [FK_TESSERA_CLIENTE]
GO
ALTER TABLE [dbo].[UTENTE]  WITH CHECK ADD  CONSTRAINT [FK_CLIENTE_BIBLIOTECA] FOREIGN KEY([BIBLIOTECA])
REFERENCES [dbo].[BIBLIOTECA] ([BIBLIOTECA])
GO
ALTER TABLE [dbo].[UTENTE] CHECK CONSTRAINT [FK_CLIENTE_BIBLIOTECA]
GO
ALTER TABLE [dbo].[UTENTE]  WITH CHECK ADD  CONSTRAINT [FK_CLIENTE_CITTA] FOREIGN KEY([CITTA])
REFERENCES [dbo].[CITTA] ([CITTA])
GO
ALTER TABLE [dbo].[UTENTE] CHECK CONSTRAINT [FK_CLIENTE_CITTA]
GO
