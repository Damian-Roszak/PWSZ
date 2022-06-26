<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" EnableViewState="true" Inherits="Lista6zad4.WebForm1" %>

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
            <div class="segment">                
                <div class="pay">
                    <asp:Button ID="Button7" runat="server" Font-Size="XX-Large" Text="Zapłać" OnClick="Button7_Click" />
                    <asp:Label ID="inf" runat="server"></asp:Label>
                </div>
                <br />
            </div>

            <div class="segment">
            <br />
              <asp:Label ID="Label8" runat="server" class="produkt" Text="Nazwa Produktu 1"></asp:Label>
            <br />
            <div class="obrazek">
                <asp:Image ID="Image1" runat="server" Height="162px" Width="282px" src="h.jpg" />
            </div>

            <div class="opis">
                <asp:Label ID="Label1" runat="server" Font-Size="XX-Large" Text="Opis produktu "></asp:Label>
            </div>

            <div class="stan">
                <asp:Label ID="Label3" runat="server" Font-Size="XX-Large" Text="Stan magazynowy: "></asp:Label>
                <asp:Label ID="Label37" runat="server" Font-Size="XX-Large" Text="?"></asp:Label>
                <br />
                <asp:Label ID="Label6" runat="server" Font-Bold="True" Font-Size="Large" Text="ILE SZTUK: "></asp:Label>
&nbsp;<asp:TextBox ID="TextBox1" runat="server" OnTextChanged="TextBox1_TextChanged">1</asp:TextBox>
&nbsp;<br />
                <br />
                <asp:Label ID="Label30" runat="server" Font-Bold="True" Font-Size="Large" Text="DOSTAWA: "></asp:Label>
                <asp:DropDownList ID="DropDownList1" runat="server" Font-Size="Large">
                    <asp:ListItem Selected="True">Kurier</asp:ListItem>
                    <asp:ListItem>Poczta</asp:ListItem>
                    <asp:ListItem>Do domu</asp:ListItem>
                    <asp:ListItem>InPost</asp:ListItem>
                </asp:DropDownList>
                <br />
                <br />
                <asp:Label ID="Label31" runat="server" Font-Bold="True" Font-Size="Large" Text="SPOSÓB PŁATNOŚCI: "></asp:Label>
                <asp:DropDownList ID="DropDownList7" runat="server" Font-Size="Large">
                    <asp:ListItem Selected="True">Karta</asp:ListItem>
                    <asp:ListItem>Przelew</asp:ListItem>
                    <asp:ListItem>Przy odbiorze</asp:ListItem>
                    <asp:ListItem>Kupon</asp:ListItem>
                </asp:DropDownList>
                <br />
                
            </div>

            <div class="kup">
                <asp:Button ID="Button1" runat="server" Font-Size="XX-Large" Text="Dodaj do Koszyka" OnClick="Button1_Click" />
            </div>
            <br />
            <br />
            <br />
          </div>
            
          <div class="segment">
            <br />
              <asp:Label ID="Label7" runat="server" class="produkt" Text="Nazwa Produktu 2"></asp:Label>
            <br />
            <div class="obrazek">
                <asp:Image ID="Image2" runat="server" Height="167px" Width="287px" src="h.jpg" />
            </div>

            <div class="opis">
                <asp:Label ID="Label2" runat="server" Font-Size="XX-Large" Text="Opis produktu "></asp:Label>
            </div>

            <div class="stan">
                <asp:Label ID="Label4" runat="server" Font-Size="XX-Large" Text="Stan magazynowy: "></asp:Label>

                <asp:Label ID="Label38" runat="server" Font-Size="XX-Large" Text="?"></asp:Label>

                <br />
                <br />
                <asp:Label ID="Label5" runat="server" Font-Bold="True" Font-Size="Large" Text="ILE SZTUK: "></asp:Label>
&nbsp;<asp:TextBox ID="TextBox2" runat="server" OnTextChanged="TextBox2_TextChanged">1</asp:TextBox>
&nbsp;<br />
                <br />
                <asp:Label ID="Label29" runat="server" Font-Bold="True" Font-Size="Large" Text="DOSTAWA: "></asp:Label>
                <asp:DropDownList ID="DropDownList2" runat="server" Font-Size="Large">
                    <asp:ListItem Selected="True">Kurier</asp:ListItem>
                    <asp:ListItem>Poczta</asp:ListItem>
                    <asp:ListItem>Do domu</asp:ListItem>
                    <asp:ListItem>InPost</asp:ListItem>
                </asp:DropDownList>
                <br />
                <br />
                <asp:Label ID="Label32" runat="server" Font-Bold="True" Font-Size="Large" Text="SPOSÓB PŁATNOŚCI: "></asp:Label>
                <asp:DropDownList ID="DropDownList8" runat="server" Font-Size="Large">
                    <asp:ListItem Selected="True">Karta</asp:ListItem>
                    <asp:ListItem>Przelew</asp:ListItem>
                    <asp:ListItem>Przy odbiorze</asp:ListItem>
                    <asp:ListItem>Kupon</asp:ListItem>
                </asp:DropDownList>
              </div>

            <div class="kup">
                <asp:Button ID="Button2" runat="server" Font-Size="XX-Large" Text="Dodaj do Koszyka" OnClick="Button2_Click" />
            </div>
            <br />
            <br />
            <br />
          </div>

          <div class="segment">
            <br />
              <asp:Label ID="Label9" runat="server" class="produkt" Text="Nazwa Produktu 3"></asp:Label>
            <br />
            <div class="obrazek">
                <asp:Image ID="Image3" runat="server" Height="162px" Width="282px" src="h.jpg" />
            </div>

            <div class="opis">
                <asp:Label ID="Label10" runat="server" Font-Size="XX-Large" Text="Opis produktu "></asp:Label>
            </div>

            <div class="stan">
                <asp:Label ID="Label11" runat="server" Font-Size="XX-Large" Text="Stan magazynowy: "></asp:Label>
                <asp:Label ID="Label39" runat="server" Font-Size="XX-Large" Text="?"></asp:Label>
                <br />
                <asp:Label ID="Label12" runat="server" Font-Bold="True" Font-Size="Large" Text="ILE SZTUK: "></asp:Label>
&nbsp;<asp:TextBox ID="TextBox3" runat="server">1</asp:TextBox>
&nbsp;<br />
                <br />
                <asp:Label ID="Label28" runat="server" Font-Bold="True" Font-Size="Large" Text="DOSTAWA: "></asp:Label>
                <asp:DropDownList ID="DropDownList3" runat="server" Font-Size="Large">
                    <asp:ListItem>Kurier</asp:ListItem>
                    <asp:ListItem>Poczta</asp:ListItem>
                    <asp:ListItem>Do domu</asp:ListItem>
                    <asp:ListItem>InPost</asp:ListItem>
                </asp:DropDownList>
                <br />
                <br />
                <asp:Label ID="Label33" runat="server" Font-Bold="True" Font-Size="Large" Text="SPOSÓB PŁATNOŚCI: "></asp:Label>
                <asp:DropDownList ID="DropDownList9" runat="server" Font-Size="Large">
                    <asp:ListItem>Karta</asp:ListItem>
                    <asp:ListItem>Przelew</asp:ListItem>
                    <asp:ListItem>Przy odbiorze</asp:ListItem>
                    <asp:ListItem>Kupon</asp:ListItem>
                </asp:DropDownList>
                <br />
                
            </div>

            <div class="kup">
                <asp:Button ID="Button3" runat="server" Font-Size="XX-Large" Text="Dodaj do Koszyka" OnClick="Button3_Click" />
            </div>
            <br />
            <br />
            <br />
          </div>
            
          <div class="segment">
            <br />
              <asp:Label ID="Label13" runat="server" class="produkt" Text="Nazwa Produktu 4"></asp:Label>
            <br />
            <div class="obrazek">
                <asp:Image ID="Image4" runat="server" Height="167px" Width="287px" src="h.jpg" />
            </div>

            <div class="opis">
                <asp:Label ID="Label14" runat="server" Font-Size="XX-Large" Text="Opis produktu "></asp:Label>
            </div>

            <div class="stan">
                <asp:Label ID="Label15" runat="server" Font-Size="XX-Large" Text="Stan magazynowy: "></asp:Label>

                <asp:Label ID="Label40" runat="server" Font-Size="XX-Large" Text="?"></asp:Label>

                <br />
                <br />
                <asp:Label ID="Label16" runat="server" Font-Bold="True" Font-Size="Large" Text="ILE SZTUK: "></asp:Label>
&nbsp;<asp:TextBox ID="TextBox4" runat="server" Font-Size="Large" OnTextChanged="TextBox4_TextChanged">1</asp:TextBox>
&nbsp;<br />
                <br />
                <asp:Label ID="Label25" runat="server" Font-Bold="True" Font-Size="Large" Text="DOSTAWA: "></asp:Label>
                <asp:DropDownList ID="DropDownList4" runat="server" Font-Size="Large">
                    <asp:ListItem>Kurier</asp:ListItem>
                    <asp:ListItem>Poczta</asp:ListItem>
                    <asp:ListItem>Do domu</asp:ListItem>
                    <asp:ListItem>InPost</asp:ListItem>
                </asp:DropDownList>
                <br />
                <br />
                <asp:Label ID="Label34" runat="server" Font-Bold="True" Font-Size="Large" Text="SPOSÓB PŁATNOŚCI: "></asp:Label>
                <asp:DropDownList ID="DropDownList10" runat="server" Font-Size="Large">
                    <asp:ListItem>Karta</asp:ListItem>
                    <asp:ListItem>Przelew</asp:ListItem>
                    <asp:ListItem>Przy odbiorze</asp:ListItem>
                    <asp:ListItem>Kupon</asp:ListItem>
                </asp:DropDownList>
                <br />
              </div>

            <div class="kup">
                <asp:Button ID="Button4" runat="server" Font-Size="XX-Large" Text="Dodaj do Koszyka" OnClick="Button4_Click" />
            </div>
            <br />
            <br />
            <br />
          </div>

          <div class="segment">
            <br />
              <asp:Label ID="Label17" runat="server" class="produkt" Text="Nazwa Produktu 5"></asp:Label>
            <br />
            <div class="obrazek">
                <asp:Image ID="Image5" runat="server" Height="162px" Width="282px" src="h.jpg" />
            </div>

            <div class="opis">
                <asp:Label ID="Label18" runat="server" Font-Size="XX-Large" Text="Opis produktu "></asp:Label>
            </div>

            <div class="stan">
                <asp:Label ID="Label19" runat="server" Font-Size="XX-Large" Text="Stan magazynowy: "></asp:Label>
                <asp:Label ID="Label41" runat="server" Font-Size="XX-Large" Text="?"></asp:Label>
                <br />
                <asp:Label ID="Label20" runat="server" Font-Bold="True" Font-Size="Large" Text="ILE SZTUK: "></asp:Label>
&nbsp;<asp:TextBox ID="TextBox5" runat="server">1</asp:TextBox>
&nbsp;<br />
                <br />
                <asp:Label ID="Label26" runat="server" Font-Bold="True" Font-Size="Large" Text="DOSTAWA: "></asp:Label>
                <asp:DropDownList ID="DropDownList5" runat="server" Font-Size="Large">
                    <asp:ListItem>Kurier</asp:ListItem>
                    <asp:ListItem>Poczta</asp:ListItem>
                    <asp:ListItem>Do domu</asp:ListItem>
                    <asp:ListItem>InPost</asp:ListItem>
                </asp:DropDownList>
                <br />
                <br />
                <asp:Label ID="Label35" runat="server" Font-Bold="True" Font-Size="Large" Text="SPOSÓB PŁATNOŚCI: "></asp:Label>
                <asp:DropDownList ID="DropDownList11" runat="server" Font-Size="Large">
                    <asp:ListItem>Karta</asp:ListItem>
                    <asp:ListItem>Przelew</asp:ListItem>
                    <asp:ListItem>Przy odbiorze</asp:ListItem>
                    <asp:ListItem>Kupon</asp:ListItem>
                </asp:DropDownList>
                <br />
                
            </div>

            <div class="kup">
                <asp:Button ID="Button5" runat="server" Font-Size="XX-Large" Text="Dodaj do Koszyka" OnClick="Button5_Click" />
            </div>
            <br />
            <br />
            <br />
          </div>
            
          <div class="segment">
            <br />
              <asp:Label ID="Label21" runat="server" class="produkt" Text="Nazwa Produktu 6"></asp:Label>
            <br />
            <div class="obrazek">
                <asp:Image ID="Image6" runat="server" Height="167px" Width="287px" src="h.jpg" />
            </div>

            <div class="opis">
                <asp:Label ID="Label22" runat="server" Font-Size="XX-Large" Text="Opis produktu "></asp:Label>
            </div>

            <div class="stan">
                <asp:Label ID="Label23" runat="server" Font-Size="XX-Large" Text="Stan magazynowy: "></asp:Label>

                <asp:Label ID="Label42" runat="server" Font-Size="XX-Large" Text="?"></asp:Label>

                <br />
                <br />
                <asp:Label ID="Label24" runat="server" Font-Bold="True" Font-Size="Large" Text="ILE SZTUK: "></asp:Label>
&nbsp;<asp:TextBox ID="TextBox6" runat="server">1</asp:TextBox>
&nbsp;<br />
                <br />
                <asp:Label ID="Label27" runat="server" Font-Bold="True" Font-Size="Large" Text="DOSTAWA: "></asp:Label>
                <asp:DropDownList ID="DropDownList6" runat="server" Font-Size="Large">
                    <asp:ListItem>Kurier</asp:ListItem>
                    <asp:ListItem>Poczta</asp:ListItem>
                    <asp:ListItem>Do domu</asp:ListItem>
                    <asp:ListItem>InPost</asp:ListItem>
                </asp:DropDownList>
                <br />
                <br />
                <asp:Label ID="Label36" runat="server" Font-Bold="True" Font-Size="Large" Text="SPOSÓB PŁATNOŚCI: "></asp:Label>
                <asp:DropDownList ID="DropDownList12" runat="server" Font-Size="Large">
                    <asp:ListItem>Karta</asp:ListItem>
                    <asp:ListItem>Przelew</asp:ListItem>
                    <asp:ListItem>Przy odbiorze</asp:ListItem>
                    <asp:ListItem>Kupon</asp:ListItem>
                </asp:DropDownList>
              </div>

            <div class="kup">
                <asp:Button ID="Button6" runat="server" Font-Size="XX-Large" Text="Dodaj do Koszyka" OnClick="Button6_Click" />
            </div>
            <br />
            <br />
            <br />
          </div>
        </div>
    </form>
</body>
</html>
