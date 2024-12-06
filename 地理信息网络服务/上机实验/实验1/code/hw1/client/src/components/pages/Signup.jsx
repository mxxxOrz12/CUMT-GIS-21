import React, { useState, useEffect } from "react";
import { LockOutlined, UserOutlined } from "@ant-design/icons";
import { Button, Checkbox, Form, Input, message, Space } from "antd";
import "./Signup.css";
import { Card } from "antd";
import signup from "../assets/signup.png";
import axios from "axios";
import { useNavigate } from "react-router-dom";

const initialState = {
  username: "",
  password: "",
  confirmPassword: "",
};

const Signup = () => {
  const [isSignup, setIsSignup] = useState(false);
  const [form, setForm] = useState(initialState);
  const [messageApi, contextHolder] = message.useMessage();
  const navigate = useNavigate();

  const switchMode = () => {
    setIsSignup((prevIsSignup) => !prevIsSignup);
  };

  const [myForm] = Form.useForm();
  const [errorMessage, setErrorMessage] = useState("");
  const [successMessage, setSuccessMessage] = useState("");
  useEffect(() => {
    if (errorMessage) {
      message.error(errorMessage);
      const timer = setTimeout(() => {
        setErrorMessage("");
      }, 1000);
      return () => clearTimeout(timer);
    }
    if (successMessage) {
      message.success(successMessage);
      const timer = setTimeout(() => {
        setSuccessMessage("");
      }, 1000);
      return () => clearTimeout(timer);
    }
  }, [errorMessage, successMessage]);

  const handleSubmit = async (e) => {
    e.preventDefault();

    if (isSignup) {
      if (!form.username || !form.password || !form.confirmPassword) {
        setErrorMessage("请输入用户信息");
        return;
      }

      if (form.password !== form.confirmPassword) {
        setErrorMessage("两次密码输入不一致");
        return;
      }
    } else {
      if (!form.username || !form.password) {
        setErrorMessage("请输入用户名和密码");
        return;
      }
    }
    const { username, password } = form;
    const URL = "http://localhost:3000";
    axios
      .post(
        `${URL}/auth/${isSignup ? "signup" : "login"}`,
        {
          username,
          password,
        },
        { withCredentials: true }
      ) // 启用 withCredentials 以携带 cookie
      .then((result) => {
        if (!isSignup) {
          if (result.data == "Success") {
            setSuccessMessage("登录成功");
            myForm.resetFields();
            setTimeout(() => {
              navigate("/profile");
            }, 1000);
          }
        } else {
          setSuccessMessage("注册成功");
          setIsSignup((prevIsSignup) => !prevIsSignup);
        }
      })
      .catch((error) => {
        if (error.response) {
          if (error.response.status === 400) {
            if (isSignup) {
              setErrorMessage("用户名已存在");
            } else {
              setErrorMessage("密码错误");
            }
          } else if (error.response.status === 404) {
            setErrorMessage("找不到该用户");
          } else {
            setErrorMessage("服务器错误，请稍后再试");
          }
        } else {
          setErrorMessage("网络错误，请检查你的网络连接");
        }
        myForm.resetFields();
      });
  };

  const handleChange = (e) => {
    setForm({ ...form, [e.target.name]: e.target.value });
  };

  return (
    <div className="login-background">
      <div className="login-left-wrapper">
        <Card className="login-Card">
          <p className="login-header">{isSignup ? "注册" : "登录"}</p>
          <Form
            form={myForm}
            name="normal_login"
            className="login-form"
            initialValues={{
              remember: true,
            }}
            onSubmit={handleSubmit}
          >
            <Form.Item
              name="username"
              rules={[
                {
                  required: true,
                  message: "请输入用户名!",
                },
              ]}
            >
              <Input
                prefix={<UserOutlined className="site-form-item-icon" />}
                placeholder="用户名"
                onChange={handleChange}
                name="username"
                required
              />
            </Form.Item>
            <Form.Item
              name="password"
              rules={[
                {
                  required: true,
                  message: "请输入密码",
                },
              ]}
            >
              <Input
                prefix={<LockOutlined className="site-form-item-icon" />}
                type="password"
                placeholder="密码"
                onChange={handleChange}
                name="password"
                required
              />
            </Form.Item>
            {isSignup && (
              <Form.Item
                name="confirmPassword"
                rules={[
                  {
                    required: true,
                    message: "请再次输入密码",
                  },
                ]}
              >
                <Input
                  prefix={<LockOutlined className="site-form-item-icon" />}
                  type="password"
                  placeholder="再次输入密码"
                  onChange={handleChange}
                  name="confirmPassword"
                  required
                />
              </Form.Item>
            )}

            <Form.Item>
              <Form.Item name="remember" valuePropName="checked" noStyle>
                {isSignup ? "" : <Checkbox>记住我</Checkbox>}
              </Form.Item>

              {isSignup ? (
                ""
              ) : (
                <a className="login-form-forgot" href="">
                  忘记密码？
                </a>
              )}
            </Form.Item>

            <Form.Item>
              <Button
                type="primary"
                htmlType="submit"
                className="login-form-button"
                onClick={handleSubmit}
              >
                {isSignup ? "注册" : "登录"}
              </Button>
              <div className="login-switch">
                <span onClick={switchMode}>
                  {isSignup ? "返回登录" : "现在注册"}
                </span>
              </div>
            </Form.Item>
          </Form>
        </Card>
      </div>

      <div className="login-right-image">
        <img src={signup} alt="" />
      </div>
    </div>
  );
};

export default Signup;
