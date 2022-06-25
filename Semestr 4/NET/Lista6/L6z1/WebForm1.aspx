<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Lista6zad1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Lista 6 zad 1</title>
</head>
<body>
    <form id="form1" runat="server">
        <div id="div1" style="font-size:25px;">
            Lista 6 zad 1:<br />
            <asp:Label ID="Label1" runat="server" Font-Names="Arial" Font-Size="X-Large" Text="Imię: "></asp:Label>
            <asp:TextBox ID="TextBox1" runat="server">Damian</asp:TextBox>
            <br />
            <asp:Label ID="Label2" runat="server" Font-Names="Arial" Font-Size="X-Large" Text="Nazwisko:"></asp:Label>
            <asp:TextBox ID="TextBox2" runat="server">Roszak</asp:TextBox>
            <br />
            <asp:Label ID="Label3" runat="server" Font-Names="Arial" Font-Size="X-Large" Text="Wiek: "></asp:Label>
            <asp:TextBox ID="TextBox3" runat="server">37</asp:TextBox>
            <br />
            <asp:Label ID="Label4" runat="server" Font-Names="Arial" Font-Size="X-Large" Text="PESEL: "></asp:Label>
            <asp:TextBox ID="TextBox4" runat="server">12345679</asp:TextBox>
            <br />
            <asp:Label ID="Label5" runat="server" Font-Names="Arial" Font-Size="X-Large" Text="kraj: "></asp:Label>
            <asp:TextBox ID="TextBox5" runat="server">POLSKA</asp:TextBox>
            <br />
            <asp:Label ID="Label6" runat="server" Font-Names="Arial" Font-Size="X-Large" Text="miasto: "></asp:Label>
            <asp:TextBox ID="TextBox6" runat="server">Głuchołazy</asp:TextBox>
            <br />
            <asp:Label ID="Label7" runat="server" Font-Names="Arial" Font-Size="X-Large" Text="ulica"></asp:Label>
            <asp:TextBox ID="TextBox7" runat="server">Plac Basztowy</asp:TextBox>
            <br />
            <asp:Label ID="Label8" runat="server" Font-Names="Arial" Font-Size="X-Large" Text="nr domu/mieszkania"></asp:Label>
            <asp:TextBox ID="TextBox8" runat="server">4/4</asp:TextBox>
            <br />
            Czcionka:
            <asp:DropDownList ID="DropDownList1" runat="server">
                <asp:ListItem Selected="True">Verdana</asp:ListItem>
                <asp:ListItem>Times</asp:ListItem>
                <asp:ListItem>Arial</asp:ListItem>
                <asp:ListItem>Centaur</asp:ListItem>
                <asp:ListItem>Consolas</asp:ListItem>
                <asp:ListItem>Monotype</asp:ListItem>
                <asp:ListItem>Tahoma</asp:ListItem>
                <asp:ListItem>Vineta</asp:ListItem>
            </asp:DropDownList>
            &nbsp;<br />
            kolor:
            <asp:DropDownList ID="DropDownList2" runat="server">
                <asp:ListItem>Red</asp:ListItem>
                <asp:ListItem>Green</asp:ListItem>
                <asp:ListItem>Blue</asp:ListItem>
                <asp:ListItem>Yellow</asp:ListItem>
                <asp:ListItem>White</asp:ListItem>
                <asp:ListItem>Cyan</asp:ListItem>
                <asp:ListItem>Black</asp:ListItem>
                <asp:ListItem>Brown</asp:ListItem>
                <asp:ListItem>Pink</asp:ListItem>
                <asp:ListItem>Violet</asp:ListItem>
            </asp:DropDownList>
            <br />
            rozmiar:
            <asp:TextBox ID="TextBox9" runat="server">55</asp:TextBox>
            <br />
            pogrubienie:
            <asp:CheckBox ID="CheckBox1" runat="server" />
            <br />
            pochylenie:
            <asp:CheckBox ID="CheckBox2" runat="server" />
            <br />
            podkreślenie:
            <asp:CheckBox ID="CheckBox3" runat="server" />
            <br />
&nbsp;<br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <asp:Button ID="Button1" runat="server" Font-Names="Arial Black" Font-Size="X-Large" Text="Wyślij na server" OnClick="Button1_Click" />
            <br />
        </div>
        <p>
            &nbsp;</p>
    </form>
</body>
</html>
