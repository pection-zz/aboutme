Spree.Collections.States = Backbone.Collection.extend({
  initialize: function (models, options) {
    this.country_id = options.country_id
  },

  url: function () {
    return Spree.pathFor('api/states?country_id=' + this.country_id)
  },

  parse: function(resp, options) {
    return resp.states;
  }
})
