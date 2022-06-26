<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm2.aspx.cs"  Inherits="Lista6zad4.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <link href="styl.css" rel="stylesheet" type="text/css" />
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            
            <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
            <h1>
                 <%=Session["Data"] %>
            </h1>
            
        </div>
    </form>
</body>
</html>
