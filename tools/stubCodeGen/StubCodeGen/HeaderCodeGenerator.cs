using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StubCodeGen
{
    public partial class HeaderCodeGenerator : HeaderCodeGeneratorBase
    {
        public HeaderCodeGenerator(List<MethodDefinition> definitions)
        {
            this.Definitions = definitions;
        }
        public List<MethodDefinition> Definitions { get; set; }
    }
}