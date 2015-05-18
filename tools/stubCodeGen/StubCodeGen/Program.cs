using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace StubCodeGen
{
    public class MethodArgument
    {
        public string Type { get; set;}
        public string Name { get; set; }
        public override string ToString() {
            return String.Format("{0} {1}", Type, Name);
        }
    }

    public class MethodDefinition
    {
        public MethodDefinition(string line)
        {
            Args = new List<MethodArgument>();
            var delimited = line.Split(new char[] { ',' });

            ReturnType = delimited[0];
            Name = delimited[1];
            
            if (delimited.Length == 2) return;
            
            for (int i = 2; i < delimited.Length; i += 2)
                Args.Add(new MethodArgument() {
                    Type = delimited[i],
                    Name = delimited[i + 1]
                });
        }
        public string Name { get; set; }
        public string ReturnType { get; set; }
        public List<MethodArgument> Args { get; private set;}
        public override string ToString() {
            return String.Format("{0} {1}({2});", ReturnType, Name, String.Join(", ", Args));
        }
    }

    class Program
    {
        static void Main(string[] args) {
            var instances = (from l in File.ReadAllLines("apis.txt") select new MethodDefinition(l)).ToList();
            File.WriteAllText("GeneratedTrampolines.g.cpp", new CppCodeGenerator(instances).TransformText());
            File.WriteAllText("GeneratedTrampolines.g.h", new HeaderCodeGenerator(instances).TransformText());
            File.WriteAllText("ITrampolineClient.g.h", new InterfaceCodeGenerator(instances).TransformText());
        }
    }
}
