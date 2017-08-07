const path = require('path')
const webpack = require('webpack')
const HtmlWebpackPlugin = require('html-webpack-plugin')

module.exports = {
  entry: [
    'webpack-dev-server/client?http://localhost:8080',
    'webpack/hot/only-dev-server',
    './example/root.re'
  ],
  output: {
    filename: '[name].js',
    path: path.join(__dirname, 'bundledOutputs')
  },
  devServer: {
    contentBase: './bundledOutputs',
    historyApiFallback: true
  },
  plugins: [
    new HtmlWebpackPlugin({
      title: 'React Rotuer',
      template: 'example/index.html'
    }),
    new webpack.HotModuleReplacementPlugin()
  ],
  module: {
    rules: [
      { test: /\.(re|ml)$/, use: 'bs-loader' }
    ]
  },
  resolve: {
    extensions: ['.re', '.ml', '.js']
  }
};

// module.exports = {
//   entry: {
//     root: './example/root.re'
//   },
//   output: {
//     path: path.resolve(__dirname, 'bundledOutputs'),
//     filename: '[name].js'
//   },
//   devServer: {
//     contentBase: './bundledOutputs',
//     historyApiFallback: true
//   },
//   plugins: [
//     new HtmlWebpackPlugin({
//       title: 'VR',
//       template: 'example/index.html'
//     })
//   ],
//   module: {
//     rules: [
//       { test: /\.(re|ml)$/, use: 'bs-loader' }
//     ]
//   },
//   resolve: {
//     extensions: ['.re', '.ml', '.js']
//   }
// }
