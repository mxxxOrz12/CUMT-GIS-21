<%
If Request.TotalBytes > 0 Then
	Dim png
	' get bytearray
	png = Request.BinaryRead(Request.TotalBytes)

	' add headers for download dialog-box
	Response.ContentType = "image/png"
	Response.AddHeader "Content-Disposition", "attachment; filename=" & Request.QueryString("name")
	Response.BinaryWrite png
End If
%>