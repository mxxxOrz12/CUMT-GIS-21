<%
If Request.TotalBytes > 0 Then
	Dim jpg
	' get bytearray
	jpg = Request.BinaryRead(Request.TotalBytes)

	' add headers for download dialog-box
	Response.ContentType = "image/jpeg"
	Response.AddHeader "Content-Disposition", "attachment; filename=" & Request.QueryString("name")
	Response.BinaryWrite jpg
End If
%>