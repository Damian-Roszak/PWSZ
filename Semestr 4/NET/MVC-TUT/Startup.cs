using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(MVCTut.Startup))]
namespace MVCTut
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
