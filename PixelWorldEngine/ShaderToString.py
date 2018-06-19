import sys

shaderFile = open("shader.hlsl", "r")

data = shaderFile.readlines()

shaderFile.close()

result = ""

result += "#include \"pch.hpp\"\n\n"

result += "namespace PixelWorldEngine {\n\t"

result += "constexpr char defaultShaderCode[] = \""

for item in data:
    item = item.replace('\n', ' ')
    result += item + r'\n'
    pass

result += "\";"

result += "\n}"

hppFile = open("EngineDefaultResource.hpp", "w")

hppFile.write(result)

hppFile.close()



