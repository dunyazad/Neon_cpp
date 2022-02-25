#include <Neon/Graphics/Shader.h>

NeShader::NeShader()
{
}

NeShader::~NeShader()
{
}

bool NeShader::Build()
{
	if (this->vertexShaderFileName.empty() == false)
	{
		ifstream ifs;
		ifs.open(this->vertexShaderFileName, ios_base::in);
		if (ifs.is_open() == false) {
			SPDLOG_CRITICAL("Could not open the file - {}'", this->vertexShaderFileName);
			return false;
		}

		this->vertexShaderCode = string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	}

	if (this->vertexShaderCode.empty() == false)
	{
		this->vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		const char* c_str = this->vertexShaderCode.c_str();
		glShaderSource(this->vertexShaderID, 1, &c_str, nullptr);
		glCompileShader(this->vertexShaderID);

		int success;
		char infoLog[512];
		glGetShaderiv(this->vertexShaderID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(this->vertexShaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			return false;
		}
	}

	if (this->geometryShaderFileName.empty() == false)
	{
		ifstream ifs;
		ifs.open(this->geometryShaderFileName, ios_base::in);
		if (ifs.is_open() == false) {
			SPDLOG_CRITICAL("Could not open the file - {}'", this->geometryShaderFileName);
			return false;
		}

		this->geometryShaderCode = string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	}

	if (this->geometryShaderCode.empty() == false)
	{
		this->geometryShaderID = glCreateShader(GL_GEOMETRY_SHADER);
		const char* c_str = this->geometryShaderCode.c_str();
		glShaderSource(this->geometryShaderID, 1, &c_str, nullptr);
		glCompileShader(this->geometryShaderID);

		int success;
		char infoLog[512];
		glGetShaderiv(this->geometryShaderID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(this->geometryShaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::GEOMETRY::COMPILATION_FAILED\n" << infoLog << std::endl;
			return false;
		}
	}

	if (this->fragmentShaderFileName.empty() == false)
	{
		ifstream ifs;
		ifs.open(this->fragmentShaderFileName, ios_base::in);
		if (ifs.is_open() == false) {
			SPDLOG_CRITICAL("Could not open the file - {}'", this->fragmentShaderFileName);
			return false;
		}

		this->fragmentShaderCode = string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	}

	if (this->fragmentShaderCode.empty() == false)
	{
		this->fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		const char* c_str = this->fragmentShaderCode.c_str();
		glShaderSource(this->fragmentShaderID, 1, &c_str, nullptr);
		glCompileShader(this->fragmentShaderID);

		int success;
		char infoLog[512];
		glGetShaderiv(this->fragmentShaderID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(this->fragmentShaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
			return false;
		}
	}

	this->shaderProgramID = glCreateProgram();
	if (this->vertexShaderCode.empty() == false)
	{
		glAttachShader(this->shaderProgramID, this->vertexShaderID);
	}
	if (this->geometryShaderCode.empty() == false)
	{
		glAttachShader(this->shaderProgramID, this->geometryShaderID);
	}
	if (this->fragmentShaderCode.empty() == false)
	{
		glAttachShader(this->shaderProgramID, this->fragmentShaderID);
	}
	glLinkProgram(this->shaderProgramID);

	int success;
	char infoLog[512];
	glGetProgramiv(this->shaderProgramID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(this->shaderProgramID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		return false;
	}

	if (this->vertexShaderCode.empty() == false)
	{
		glDeleteShader(this->vertexShaderID);
	}
	if (this->geometryShaderCode.empty() == false)
	{
		glDeleteShader(this->geometryShaderID);
	}
	if (this->fragmentShaderCode.empty() == false)
	{
		glDeleteShader(this->fragmentShaderID);
	}





	GLint i;
	GLint count;

	GLint size; // size of the variable
	GLenum type; // type of the variable (float, vec3 or mat4, etc)

	const GLsizei bufSize = 16; // maximum name length
	GLchar name[bufSize]; // variable name in GLSL
	GLsizei length; // name length

	glGetProgramiv(this->shaderProgramID, GL_ACTIVE_ATTRIBUTES, &count);
	printf("Active Attributes: %d\n", count);

	for (i = 0; i < count; i++)
	{
		glGetActiveAttrib(this->shaderProgramID, (GLuint)i, bufSize, &length, &size, &type, name);

		attributeIndexNameTable[i] = name;
		attributeNameIndexTable[name] = i;

		printf("Attribute #%d Type: %u Name: %s\n", i, type, name);
	}

	glGetProgramiv(this->shaderProgramID, GL_ACTIVE_UNIFORMS, &count);
	printf("Active Uniforms: %d\n", count);

	for (i = 0; i < count; i++)
	{
		glGetActiveUniform(this->shaderProgramID, (GLuint)i, bufSize, &length, &size, &type, name);

		uniformIndexNameTable[i] = name;
		uniformNameIndexTable[name] = i;

		printf("Uniform #%d Type: %u Name: %s\n", i, type, name);
	}

	return true;
}

void NeShader::Use()
{
	glUseProgram(this->shaderProgramID);
}

bool NeShader::SetUniformMatrix4(const string& name, const glm::mat4& m)
{
	if (this->uniformNameIndexTable.count(name) == 0)
	{
		SPDLOG_CRITICAL("There is no uniform name : \"{}\"", name.c_str());
		return false;
	}
	else
	{
		glUniformMatrix4fv(this->uniformNameIndexTable[name], 1, false, glm::value_ptr(m));
		return true;
	}
}
