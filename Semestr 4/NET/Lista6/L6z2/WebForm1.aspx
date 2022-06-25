<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Lista6zad2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="Label1" runat="server" Font-Size="50px" Text="Wynik" Width="500px" name="calc_result"></asp:Label>
            <br />
            <asp:Label ID="Label2" runat="server" Font-Size="XX-Large" Text="Liczba 1:" Width="125px" name="calc_result"></asp:Label>
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <br />
            <asp:Label ID="Label3" runat="server" Font-Size="XX-Large" Text="Liczba 2:" Width="125px" name="calc_result"></asp:Label>
            <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
            <br />
            <br />
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Button ID="BtnPlus" runat="server" Font-Size="Larger" Text="+" Width="50px" Font-Bold="True" OnClick="BtnPlus_Click" />
            <asp:Button ID="BtnMinus" runat="server" Font-Size="Larger" Text="-" Width="50px" Font-Bold="True" OnClick="BtnMinus_Click" />
            <asp:Button ID="BtnMn" runat="server" Font-Size="Larger" Text="*" Width="50px" Font-Bold="True" OnClick="BtnMn_Click" />
            <asp:Button ID="BtnDiv" runat="server" Font-Size="Larger" Text="/" Width="50px" Font-Bold="True" OnClick="BtnDiv_Click" />
            <br />
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Button ID="BtnPot" runat="server" Font-Size="Larger" Text="^" Width="50px" Font-Bold="True" OnClick="BtnPot_Click" />
            <asp:Button ID="BtnPier" runat="server" Font-Size="Larger" Text="√" Width="50px" Font-Bold="True" OnClick="BtnPier_Click" />
            <asp:Button ID="BtnModulo" runat="server" Font-Size="Larger" Text="%" Width="50px" Font-Bold="True" OnClick="BtnModulo_Click" />
            <asp:Button ID="BtnSin" runat="server" Font-Size="Larger" Text="Sin" Width="50px" Font-Bold="True" OnClick="BtnSin_Click" />
            <br />
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <br />
            <br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <br />
            <br />
            <br />
            <br />
            <br />
        </div>
    </form>
</body>
</html>
