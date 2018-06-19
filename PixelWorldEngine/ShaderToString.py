import sys

def CreateCharArray(fileName, suffixName):
    shaderFile = open(fileName + suffixName, "r")
    
    data = shaderFile.readlines()
    
    shaderFile.close()

    result = "constexpr char "+ fileName + "DefaultShaderCode[] = \""

    for item in data:
        item = item.replace('\n', ' ')
        result += item + r'\n'
    pass

    result+="\";"

    return result

result = ""

result += "#include \"pch.hpp\"\n\n"

result += "namespace PixelWorldEngine {\n"

result += "\t" + CreateCharArray("PixelWorld", ".hlsl") + "\n"
result += "\t" + CreateCharArray("Application", ".hlsl") + "\n"

result += "\n}"

hppFile = open("EngineDefaultResource.hpp", "w")

hppFile.write(result)

hppFile.close()



