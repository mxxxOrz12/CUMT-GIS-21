<%@ CODEPAGE = 65001 %>
<%
	Response.ContentType = "text/csv"
	Response.AddHeader "Content-Disposition", "attachment; filename=""StatPlanet_data.csv"""
	Dim csvData
	If Request.Form("csvdata") <> "" Then
		csvData = Request.Form("csvdata")
	Else
		csvData = Request.QueryString("csvdata")
	End If
	Response.Write csvData
%>