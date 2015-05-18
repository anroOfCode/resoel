using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StubCodeGen
{
    class GeneratorHelpers
    {
        public static string GetPassThroughArgumentString(MethodDefinition method, bool post)
        {
            if (post)
            {
                if (method.Args.Count > 0)
                    return String.Join(", ", "result", String.Join(", ", from arg in method.Args select arg.Name));
                else
                    return "result";
            }
            else
                return String.Join(", ", from arg in method.Args select arg.Name); ;
        }

        public static string GetPassThroughTypesString(MethodDefinition method, bool post)
        {
            if (post)
            {
                if (method.Args.Count > 0)
                    return String.Join(", ", method.ReturnType, String.Join(", ", from arg in method.Args select arg.Type));
                else
                    return method.ReturnType;
            }
            else
                return String.Join(", ", from arg in method.Args select arg.Type);
        }
    }
}
